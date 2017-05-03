#include <fstream>
#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "PdfConverter.hxx"
#include "Converter.hxx"
#include "Exception.hxx"

class PdfConverterTests : public TestFixture<PdfConverterTests>
{
public:
	TEST_FIXTURE( PdfConverterTests )
	{
		TEST_CASE( testPdfPrintableConvert_generateFile );
		TEST_CASE( testPdfWatermarkConvert_generateFile );
		TEST_CASE( testPdfPrintableConvert_generateContent );
		TEST_CASE( testPdfWatermarkConvert_generateContent );
		TEST_CASE( testPdfConvert_withInexistentOriginal );
		TEST_CASE( testPdfConvert_polymorphicCall );
	}

	/**
	 * The setUp method is automatically called before each test
	 */
	void setUp()
	{
		LibFileSystem::createNetDirectory( "config" );
		LibFileSystem::createNetDirectory( "generated" );
		LibFileSystem::createNetDirectory( "originals" );
	}
	/**
	 * The tearDown method is automatically called after each test
	 */
	void tearDown()
	{
		LibFileSystem::cleanupDirectory( "config" );
		LibFileSystem::cleanupDirectory( "generated" );
		LibFileSystem::cleanupDirectory( "originals" );
	}
	/**
	 * This method creates files used in tests
	 */
	void createOriginalFile( const std::string & name )
	{
		std::string fullname( "originals/" );
		fullname += name;
		std::ofstream os( fullname.c_str() );
		os << "An original file" << std::endl;
		os.close();
	} 
	
	void testPdfPrintableConvert_generateFile()
	{
		PdfConverter converter;
		createOriginalFile( "Original.odt" );
		converter.convert( "originals/Original.odt", "generated/Prefix" );

		ASSERT_EQUALS(
			"generated/Prefix [printable].pdf\n", 
			LibFileSystem::listDirectoryInOrder( "generated" ) 
		);
	}
	
	void testPdfWatermarkConvert_generateFile()
	{
		PdfConverter converter;
		converter.activeWatermark("Any Watermark");
		createOriginalFile( "Original.odt" );
		converter.convert( "originals/Original.odt", "generated/Prefix" );

		ASSERT_EQUALS(
			"generated/Prefix [watermark].pdf\n", 
			LibFileSystem::listDirectoryInOrder( "generated" ) 
		);
	}

	void testPdfPrintableConvert_generateContent()
	{
		PdfConverter converter;
		createOriginalFile( "Original.odt" );
		converter.convert( "originals/Original.odt", "generated/Prefix" );

		ASSERT_EQUALS(
			"PDF generated from 'originals/Original.odt'. Watermark: ''\n", 
			LibFileSystem::fileContent( "generated/Prefix [printable].pdf" ) 
		);
	}

	void testPdfWatermarkConvert_generateContent()
	{
		PdfConverter converter;
		converter.activeWatermark("Any Watermark");
		createOriginalFile( "Original.odt" );
		converter.convert( "originals/Original.odt", "generated/Prefix" );

		ASSERT_EQUALS(
			"PDF generated from 'originals/Original.odt'. Watermark: 'Any Watermark'\n", 
			LibFileSystem::fileContent( "generated/Prefix [watermark].pdf" ) 
		);
	}

	void testPdfConvert_withInexistentOriginal()
	{
		PdfConverter converter;

		try
		{
			converter.convert( "originals/Original.odt", "generated/Prefix" );
			FAIL( "An exception should be caught!" );		
		}
		catch ( std::exception & e)
		{
			ASSERT_EQUALS(
				"The original file does not exist",
				e.what()
			)
		}
	}

	void testPdfConvert_polymorphicCall()
	{
		PdfConverter pdf;
		Converter * converter = &pdf;
		createOriginalFile( "Original.odt" );
		converter->convert( "originals/Original.odt", "generated/Prefix" );

		ASSERT_EQUALS(
			"PDF generated from 'originals/Original.odt'. Watermark: ''\n", 
			LibFileSystem::fileContent( "generated/Prefix [printable].pdf" ) 
		)
		
	}
	
};

REGISTER_FIXTURE( PdfConverterTests )
