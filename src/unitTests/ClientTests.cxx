#include "MiniCppUnit.hxx"
#include "Client.hxx"

class ClientTests : public TestFixture<ClientTests>
{
public:
	TEST_FIXTURE( ClientTests )
	{
		TEST_CASE( testClientUpdate );
	
	}
	void testClientUpdate()
	{
		Client client("A client", "<a@mail.org>");
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
