#include <iostream>
#include <string>

using namespace std;

class Play {
private:
	string game;
public:
	void setGame(string g)
	{
		game = g;
	}
	string getGame() const {
		return game;
	}
};
class Wag {
public:
	void wagTail(string name) {
		cout << name << " is wagging its tail." << endl;
	}
};

class Pet {
public:
	Pet(string name, int age) {
		this->name = name;
		this->age = age;
		play = new Play;
		cout << "Pet constructor" << endl;
	}
	Pet() {
		play = new Play;
		cout << "Pet empty constructor" << endl;
	}
	~Pet() {
		if (play != NULL)
		{
			try {
				cout << "deleting " << name << "'s play pointer" << endl;
				delete play;
				play = NULL;
				system("pause");
			}
			catch (exception e) {
				cerr << e.what() << endl;
				system("pause");
			}
		}
	}
	void setName(string input) {
		name = input;
	}
	void setAge(int input) {
		age = input;
	}
	string getName() const {
		return name;
	}
	int getAge()const {
		return age;
	}
	void initPlay() {
		if (play == NULL)
		{
			play = new Play;
			cout << "Instantiated play pointer" << endl;
		}
	}
	virtual void says() = 0;
	Play *play = NULL;
private:
	string name;
	int age;
};

class Cat : public Pet {
public:
	Cat(string name, int age, string breed, string color) : Pet(name, age)
	{
		this->breed = breed;
		this->color = color;
		cout << "Cat Constructor" << endl;
	}
	Cat() {
		cout << "Cat empty constructor" << endl;
	}
	Cat(const Cat &c) :Pet(c.getName(), c.getAge())
	{
		breed = c.breed;
		color = c.color;
		play->setGame(c.play->getGame());
		cout << "Cat copy constructor" << endl;
	}
	void setBreed(string input) {
		breed = input;
	}
	void setColor(string input) {
		color = input;
	}
	string getBreed() const {
		return breed;
	}
	string getColor() const {
		return color;
	}
	void says() {
		cout << getName() << " says meow." << endl;
	}
private:
	string breed;
	string color;
};
class Dog : public Pet {
public:
	Dog(string name, int age, string breed, string color) : Pet(name, age) {
		this->breed = breed;
		this->color = color;
		cout << "Dog constructor" << endl;
	}
	Dog() {
		cout << "Dog empty constructor" << endl;
	}
	//copy constructor
	Dog(const Dog&d) : Pet(d.getName(), d.getAge()) {
		breed = d.breed;
		color = d.color;
		play->setGame(d.play->getGame());
		cout << "Dog copy constructor" << endl;
	}
	void setBreed(string input) {
		breed = input;
	}
	void setColor(string input)
	{
		color = input;
	}
	string getBreed()const {
		return breed;
	}
	string getColor() const {
		return color;
	}
	void says() {
		cout << getName() << " says  arf arf!" << endl;
	}
	Wag wag;
private:
	string breed;
	string color;
};
int main()
{
	const int arrSpace = 2;
	Dog* arr[arrSpace];
	int age;
	string name;
	string color;
	string breed;
	string game;
	for (int x=0;x<2;x++)
	{
		arr[x] = new Dog;
		cout << "Enter name of the dog " << x + 1 << ": ";
		cin >> name;
		arr[x]->setName(name);
		cout << "Enter age of " << arr[x]->getName() << ": ";
		cin >> age;
		cout << "Enter breed of " << arr[x]->getName() << ": ";
		cin >> breed;
		cout << "Enter color of " << arr[x]->getName() << ": ";
		cin >> color;
		cout << "What game does " << arr[x]->getName() << " like to play:";
		cin >> game;
		arr[x]->setBreed(breed);
		arr[x]->setAge(age);
		arr[x]->setColor(color);
		arr[x]->play->setGame(game);
	}
	for (int x = 0; x < 2; x++)
	{
		cout << "Here is information about dog " << x + 1 << ":" << endl;
		cout << "Name is " << arr[x]->getName() << endl;
		cout << arr[x]->getName() << " is " << arr[x]->getAge() << " years old." << endl;
		cout << arr[x]->getName() << " is a " << arr[x]->getColor() << " " << arr[x]->getBreed() << endl;
		cout << "And " << arr[x]->getName() << " likes to play " << arr[x]->play->getGame() << endl;
		arr[x]->wag.wagTail(arr[x]->getName());
		delete arr[x];
	}
}
