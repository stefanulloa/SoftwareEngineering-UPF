#include <fstream>
#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "PdfConverter.hxx"
#include "Converter.hxx"

class PdfConverterTests : public TestFixture<PdfConverterTests>
{
public:
	TEST_FIXTURE( PdfConverterTests )
	{
		TEST_CASE( testPdfPrintableConvert_generateFile );
		
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
	
};

REGISTER_FIXTURE( PdfConverterTests )