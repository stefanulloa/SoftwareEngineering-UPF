#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "Topic.hxx"
#include <fstream>
#include "Client.hxx"

class TopicTests : public TestFixture<TopicTests>
{
public:
	TEST_FIXTURE( TopicTests )
	{

		TEST_CASE( testTopicNotify );

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


	void testTopicNotify()
	{
		Topic topic ("Some topic");
		Client *client = new Client("Another client", "anotherclient@mail.org");
		topic.subscribeClient(client);
		topic.notify("Another work", "Another author");

		ASSERT_EQUALS(
			"To: Another client <anotherclient@mail.org>\n"
			"Subject: new work Another work by Another author\n"
			"\n",
			MailStub::theInstance().sentMails()
		);

		delete(client);
	}

};

REGISTER_FIXTURE( TopicTests )
