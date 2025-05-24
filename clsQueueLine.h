#pragma once

using namespace std;
#include <iostream>
#include <queue>
#include <ctime>
#include <cstdio>
#include <iomanip>

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
			return _MyQueue.back();
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
		 cout << "Serve Time is :" << this->SERV_TIME_PREDECT * _MyQueue.size() << "Minutes" << endl;

		 cout << "|==================================\n";

	 }

	 void IssueTickets()
	 {
		 this->SetQueue_PUSH(this->GetNextClient() + 1);
		 TOTAL_TICKETS++;
	 }

	 void PrintTicketsFromLTRendRTL()
	 {
		 queue <int> Temp = _MyQueue;
		 vector <int> Elements;

		 if (_MyQueue.empty())
		 {
			 cout << "\nNo Tickets issued yet";
			 return;
		 }
		 cout << "\nTickets Liste LTR :";
		 while (!Temp.empty())
		 {
			 int val = Temp.front();
			 cout << " --> " << PREFIX << setw(3) << setfill('X') << val;
			 
			 Elements.push_back(val);
			 Temp.pop();
		 }

		 // RTL

		 cout << "\nTickets Liste RTL :";
		 for (auto it = Elements.rbegin(); it != Elements.rend(); it++)
		 {
			 cout << " --> " << PREFIX << setw(3) << setfill('X') << *it;

		 }

	 }

	 void PrintAllTickets()
	 {
		 queue <int> Temp = _MyQueue;
		 

		 if (Temp.empty())
		 {
			 cout << "\nNo Tickets issued yet";
			 return;
		 }
		 
		 while (!Temp.empty())
		 {
			 int val = Temp.front();
			 
			 cout << "\n|==================================\n";
			 cout << "|             " << PREFIX << setw(3) << setfill('X') << val << endl;
			 cout << "| ";
			 cout << "\n| ";
			 GetTime();
			 cout << "        " << endl;
			 cout << "| " << "Clients Waiting :" << val - SERVED_CLIENTS -1 << endl;
			 cout << "| " << "Serve Time in :" << (val - SERVED_CLIENTS - 1) * SERV_TIME_PREDECT << endl;
			 cout << "|==================================\n";
			  Temp.pop();
			  cout << endl;
		 }
	 }
	 void ServNextClient()
	 {
		 _MyQueue.pop();
		 SERVED_CLIENTS++;
	 }
};

