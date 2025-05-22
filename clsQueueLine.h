#pragma once

using namespace std;
#include <iostream>
#include <queue>
#include <ctime>


class clsQueueLine
{
private:
	string _Prefix="";
	short _TimeToServ=0;
	int _Client_NUM =0;
	int _ServedClients=0;
	int _TotalTickets = 0;

	queue <int> _MyQueue;

public:
	clsQueueLine(string prefx,int servTime ) {
		_Prefix = prefx;
		_TimeToServ = servTime;
	}

	void SetPrefix(string prefx) {
		_Prefix = prefx;
	}
	string GetPrefix()
	{
		return _Prefix;
	}
	__declspec(property(get = GetPrefix, put = SetPrefix)) string PREFIX;

	void SetServTime(short SVR_Time) 
	{
		_TimeToServ = SVR_Time;
	}
	short GetServTime()
	{
		return _TimeToServ;
	}
	__declspec(property(get = GetServTime, put = SetServTime)) short SERV_TIME_PREDECT;

	void SetClientNumb(int Client_Number)
	{
		_Client_NUM = Client_Number;
	}
	int GetClientNumber()
	{
		return _Client_NUM;

	}
	__declspec(property(get = GetClientNumber, put = SetClientNumb))int CLIENT_NUMBER;

	void SetServedClients(int Served_Clients)
	{
		_ServedClients = Served_Clients;
	}
	int GetServedClients()
	{
		return _ServedClients;

	}
	__declspec(property(get = GetServedClients, put = SetServedClients))int SERVED_CLIENTS;


	void SetTotalTickets(int Totalticketss)
	{
		_TotalTickets = Totalticketss;
	}
	int GetTotalTickets()
	{
		return _TotalTickets;

	}
	__declspec(property(get = GetTotalTickets, put = SetTotalTickets))int TOTAL_TICKETS;


	void SetQueue_PUSH(const int& C_Numb )
	{
		_MyQueue.push(C_Numb);
	}

	void SetQueue_POP()
	{
		_MyQueue.pop();
	}

	int GetNextClient()
	{
		if (_MyQueue.empty())
		{
			cout << "\nNo One Left";
			return 0;
		}
		else
		{
			return _MyQueue.front();
		}
	}

	size_t GetSize() const {
		return _MyQueue.size();
	}

	bool IsEmpty() const
	{
		return _MyQueue.empty();
	}

	void GetTime()
	{
		short _Day = 0, _Month = 0, _Year = 0, _Min = 0, _Sec = 0, _Houres = 0;
		time_t t = time(0);
		tm alan;

		if (localtime_s(&alan, &t) == 0)
		{
			 _Day = alan.tm_mday;
			 _Month = alan.tm_mon + 1;
			 _Year = alan.tm_year + 1900;
			 _Min = alan.tm_min;
			_Sec = alan.tm_sec;
			_Houres = alan.tm_hour;
		}

		cout << "Time : " << _Day << "\\" << _Month << "\\" << _Year << " || " << _Houres << ":" << _Min << ":" << _Sec;
	}


	 void PrintDetaillTickets()
	{
		cout << "\n\n|==================================\n";
		cout << "|          "; 
		GetTime();
		cout << "        ";




	} 

	 void PrintQINFO()
	 {
		 cout << "\n\n|==================================\n";
		 cout << "|          Queue Info              \n";
		 cout << "|==================================\n";
		 cout << "| ";
		 GetTime();
		 cout << "        \n";

		 cout << "\nPrefix : " << this->PREFIX;
		 cout << "\nTotal Tickets : " << this->TOTAL_TICKETS;
		 cout << "\nServed Clients :" << this->SERVED_CLIENTS << endl;
		 cout << "Clients Waiting :" << this->GetSize() << endl;
		// cout << "\nServe Time is :" << this->SERV_TIME_PREDECT * this->CLIENT_NUMBER << "Minutes";
		 cout << "|==================================\n";

	 }

	 void IssueTickets()
	 {
		 this->SetQueue_PUSH(this->GetNextClient() + 1);
		 TOTAL_TICKETS++;
	 }

};

