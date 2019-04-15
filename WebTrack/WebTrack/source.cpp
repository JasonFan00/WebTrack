#include "MyForm.h"
#using <System.dll>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <stdio.h>
#include <tuple>
#include <Wininet.h>  //  Note:  Some uncommonly used libraries like this need to be explicitly named in the project configurations

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::NetworkInformation;
using namespace System::Text;
using namespace WebTrack;

std::tuple<std::string, std::string> ping(String^ path);
bool Add_Search(void);

public ref class dummywrap
{
public:
	static MyForm^ form;
};

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WebTrack::MyForm form;
	Application::Run(%form);
}

std::tuple<std::string, std::string> ping(String^ path)
{
	WebRequest^ Request;
	HttpWebResponse^ Response;
	//  Try to create a request and handle all exceptions
	try
	{
		Request = WebRequest::Create(path);
	}
	catch (...)
	{
		return std::make_tuple("Exception: Unable To Ping", "Not Found");
	}
	Request->Credentials = CredentialCache::DefaultCredentials;
	try
	{
		Response = dynamic_cast<HttpWebResponse^>(Request->GetResponse());
	}
	catch (...)
	{
		return std::make_tuple("Error Response From Server", "The URL may not be a valid webpage");
	}

	return std::make_tuple(msclr::interop::marshal_as<std::string>((Response->StatusCode).ToString()), msclr::interop::marshal_as<std::string>((Response->StatusDescription)->ToString()));
}

System::Void MyForm::SearchButton_Click(System::Object^ sender, System::EventArgs^ e)  //  Note can also use the static reference.  Definition for the declaration that is inside scope of the class.
{
	//  Use wrapper class to get a reference to the form
	dummywrap::form = this;
	if (Add_Search())
	{
		this->SearchButton->Text = L"Successfully Added!"; //  Implmement multi-threading for this later
		this->SearchButton->Enabled = false;
		this->SearchButton->Refresh();
		System::Threading::Thread::Sleep(1000);  //  Note, pauses thread so delays time for listviewitem to show up in list
		this->SearchButton->Text = L"Add Site";
		this->SearchButton->Refresh();
		this->SearchButton->Enabled = true;
	}
}

//  Add inputted searches to list
bool Add_Search(void)
{
	std::string code;
	std::string desc;
	String^ sCode;
	String^ sDesc;
	String^ path = dummywrap::form->URLNameInput->Text;
	ListViewItem^ listViewItem = gcnew Windows::Forms::ListViewItem(path);

	//  Ping
	std::tie(code, desc) = ping(path);

	sCode = gcnew String(code.c_str());
	sDesc = gcnew String(desc.c_str());
	listViewItem->SubItems->Add(sCode);
	listViewItem->SubItems->Add(sDesc);

	dummywrap::form->InfoListView->Items->Add(listViewItem);
	
	return true;
}
