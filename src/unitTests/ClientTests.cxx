#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "Client.hxx"
#include <fstream>

class ClientTests : public TestFixture<ClientTests>
{
public:
	TEST_FIXTURE( ClientTests )
	{
		TEST_CASE( testClientUpdate );
	
	}

	/**
	 * setUp is automatically called before each test case
	 */
	void setUp()
	{
		LibFileSystem::createNetDirectory( "config" );
		LibFileSystem::createNetDirectory( "generated" );
		LibFileSystem::createNetDirectory( "originals" );
	}

	/**
	 * tearDown is automatically called after each test case
	 */
	void tearDown()
	{
		LibFileSystem::cleanupDirectory( "config" );
		LibFileSystem::cleanupDirectory( "generated" );
		LibFileSystem::cleanupDirectory( "originals" );
		MailStub::theInstance().removeSent();
	}

	void createOriginalFile( const std::string & name )
	{
		std::string fullname( "originals/" );
		fullname += name;
		std::ofstream os( fullname.c_str() );
		os << "An original file" << std::endl;
		os.close();
	}

	void testClientUpdate()
	{
		Client client("A client", "a@mail.org");
		client.update("A work", "An author");
		
		ASSERT_EQUALS(
			"To: A client <a@mail.org>\n"
			"Subject: new work A work by An author\n"
			"\n",
			MailStub::theInstance().sentMails()
		);
	}
	
};

REGISTER_FIXTURE( ClientTests )
