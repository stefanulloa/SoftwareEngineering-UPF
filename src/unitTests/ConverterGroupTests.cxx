#include <fstream>
#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "Converter.hxx"
#include "ConverterGroup.hxx"

class ConverterGroupTests : public TestFixture<ConverterGroupTests>
{
public:
	TEST_FIXTURE( ConverterGroupTests )
	{
		TEST_CASE( testConvert_withHtmlConverter );
		TEST_CASE( testConvert_withoutConverter );
		TEST_CASE( testConvert_withPrintablePdfConverter );
		TEST_CASE( testConvert_withWatermarkPdfConverter );
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
	
	void testConvert_withHtmlConverter()
	{
		ConverterGroup converter;
		createOriginalFile( "Original.odt" );
		converter.add("html");
		converter.convert( "originals/Original.odt", "generated/Prefix" );

		ASSERT_EQUALS(
			"generated/Prefix [multiple HTML files].war\n", 
			LibFileSystem::listDirectoryInOrder( "generated" ) 
		); 
	}
	void testConvert_withoutConverter()
	{
		ConverterGroup converter;
		createOriginalFile( "Original.odt" );
		converter.convert( "originals/Original.odt", "generated/Prefix" );

		ASSERT_EQUALS(
			"", 
			LibFileSystem::listDirectoryInOrder( "generated" ) 
		); 
	}
	void testConvert_withPrintablePdfConverter()
	{
		ConverterGroup converter;
		createOriginalFile( "Original.odt" );
		converter.add("pdf_print");
		converter.convert( "originals/Original.odt", "generated/Prefix" );

		ASSERT_EQUALS(
			"generated/Prefix [printable].pdf\n", 
			LibFileSystem::listDirectoryInOrder( "generated" ) 
		); 
	}
	void testConvert_withWatermarkPdfConverter()
	{
		ConverterGroup converter;
		createOriginalFile( "Original.odt" );
		converter.add("pdf_mark");
		converter.convert( "originals/Original.odt", "generated/Prefix" );

		ASSERT_EQUALS(
			"generated/Prefix [watermark].pdf\n", 
			LibFileSystem::listDirectoryInOrder( "generated" ) 
		); 
	}
	
};

REGISTER_FIXTURE( ConverterGroupTests )
