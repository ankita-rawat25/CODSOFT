#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	srand(time(0));
	int secret_number=rand()%100+1;
	while(true)
	{
		int guess;
		cout<<"Guess the number (between 1 and 100)";
		cin>>guess;
		
		if(guess==secret_number)
		{
			cout<<"Congratulation You Guess The Correct Number."<<endl;
			break;
		}
		
			if(guess>secret_number)
			{
				cout<<"Too high! Try again."<<endl;
			}
			else
			{
				cout<<"Too low! Try again."<<endl;	
			}
	}
	return 0;
}