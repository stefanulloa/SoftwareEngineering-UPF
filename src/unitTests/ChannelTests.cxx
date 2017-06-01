#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "Channel.hxx"
#include <fstream>

class ChannelTests : public TestFixture<ChannelTests>
{
public:
	TEST_FIXTURE( ChannelTests )
	{

		TEST_CASE( testChannelUpdate );

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


	void testChannelUpdate()
	{
		Channel channel("Classics", "Important and influencial books");
		channel.update("The trial", "Kafka");
		channel.update("Ulysses", "Joyce");

		ASSERT_EQUALS(
			"<item>\n"			
			"<title>Novelty: 'The trial' by 'Kafka'</title>\n"
			"<link>http://www.meltingpotonline.com/infoWork?author='Kafka'&title='The trial'</link>\n"
			"</item>\n"
			"<item>\n"
			"<title>Novelty: 'Ulysses' by 'Joyce'</title>\n"
			"<link>http://www.meltingpotonline.com/infoWork?author='Joyce'&title='Ulysses'</link>\n"
			"</item>\n",
			channel.listItems()
		);
	}

};

REGISTER_FIXTURE( ChannelTests )
