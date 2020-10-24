using namespace std;
struct Users
{
	string login;
	string password;
	int	role;
};

class AuthorizationSystem
{
private:
	Users users;
public:

	AuthorizationSystem();
	AuthorizationSystem(string login, string password, int role);
	~AuthorizationSystem();

	void Print();
	void SetParametrs(string login, string password, int role);
	void AddToFile(string nameFile);

	string GetLogin();
	string GetPassword();
	string GetStatus(int a);
	int GetType();

protected:
};
