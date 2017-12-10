#include<string>
using namespace std;
class UserTransaction
{
public:
	void Withdraw(string id);
	void Transfer(string id);
	void History(string id);
	UserTransaction(void);
	~UserTransaction(void);
};

