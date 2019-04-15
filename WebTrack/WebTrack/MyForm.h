#pragma once


namespace WebTrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	
	//  Switch default windows form to metro form
	public ref class MyForm : public MetroFramework::Forms::MetroForm
	{
	public:
		static MyForm^ formRef;
		MyForm(void)
		{
			InitializeComponent();
			formRef = this;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public: MetroFramework::Controls::MetroTextBox^ URLNameInput;
	public: MetroFramework::Controls::MetroButton^  SearchButton;
	private: MetroFramework::Controls::MetroLabel^  BackgroundHighlight;
	private: MetroFramework::Controls::MetroLabel^  BottomInfoText;
	public: MetroFramework::Controls::MetroLabel^  ListTitle;
	public: System::Windows::Forms::ListView^  InfoListView;
	private: System::Windows::Forms::ColumnHeader^  WebsiteURL;
	public:
	private: System::Windows::Forms::ColumnHeader^  Status;
	private: System::Windows::Forms::ColumnHeader^  Desc;

	public:







	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->URLNameInput = (gcnew MetroFramework::Controls::MetroTextBox());
			this->SearchButton = (gcnew MetroFramework::Controls::MetroButton());
			this->BackgroundHighlight = (gcnew MetroFramework::Controls::MetroLabel());
			this->BottomInfoText = (gcnew MetroFramework::Controls::MetroLabel());
			this->ListTitle = (gcnew MetroFramework::Controls::MetroLabel());
			this->InfoListView = (gcnew System::Windows::Forms::ListView());
			this->WebsiteURL = (gcnew System::Windows::Forms::ColumnHeader());
			this->Status = (gcnew System::Windows::Forms::ColumnHeader());
			this->Desc = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// URLNameInput
			// 
			// 
			// 
			// 
			this->URLNameInput->CustomButton->Image = nullptr;
			this->URLNameInput->CustomButton->Location = System::Drawing::Point(265, 1);
			this->URLNameInput->CustomButton->Name = L"";
			this->URLNameInput->CustomButton->Size = System::Drawing::Size(39, 39);
			this->URLNameInput->CustomButton->Style = MetroFramework::MetroColorStyle::Blue;
			this->URLNameInput->CustomButton->TabIndex = 1;
			this->URLNameInput->CustomButton->Theme = MetroFramework::MetroThemeStyle::Light;
			this->URLNameInput->CustomButton->UseSelectable = true;
			this->URLNameInput->CustomButton->Visible = false;
			this->URLNameInput->FontSize = MetroFramework::MetroTextBoxSize::Tall;
			this->URLNameInput->Lines = gcnew cli::array< System::String^  >(1) { L"Input URL Here" };
			this->URLNameInput->Location = System::Drawing::Point(23, 64);
			this->URLNameInput->MaxLength = 32767;
			this->URLNameInput->Name = L"URLNameInput";
			this->URLNameInput->PasswordChar = '\0';
			this->URLNameInput->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->URLNameInput->SelectedText = L"";
			this->URLNameInput->SelectionLength = 0;
			this->URLNameInput->SelectionStart = 0;
			this->URLNameInput->ShortcutsEnabled = true;
			this->URLNameInput->ShowClearButton = true;
			this->URLNameInput->Size = System::Drawing::Size(305, 41);
			this->URLNameInput->TabIndex = 1;
			this->URLNameInput->Text = L"Input URL Here";
			this->URLNameInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->URLNameInput->UseCustomBackColor = true;
			this->URLNameInput->UseCustomForeColor = true;
			this->URLNameInput->UseSelectable = true;
			this->URLNameInput->UseStyleColors = true;
			this->URLNameInput->WaterMarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(109)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(109)));
			this->URLNameInput->WaterMarkFont = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Pixel));
			this->URLNameInput->Click += gcnew System::EventHandler(this, &MyForm::metroTextBox1_Click);
			// 
			// SearchButton
			// 
			this->SearchButton->BackColor = System::Drawing::SystemColors::Window;
			this->SearchButton->FontWeight = MetroFramework::MetroButtonWeight::Regular;
			this->SearchButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->SearchButton->Location = System::Drawing::Point(369, 63);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(134, 41);
			this->SearchButton->TabIndex = 3;
			this->SearchButton->Text = L"Add Site";
			this->SearchButton->UseCustomBackColor = true;
			this->SearchButton->UseCustomForeColor = true;
			this->SearchButton->UseSelectable = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MyForm::SearchButton_Click);
			// 
			// BackgroundHighlight
			// 
			this->BackgroundHighlight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(171)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BackgroundHighlight->Location = System::Drawing::Point(24, 121);
			this->BackgroundHighlight->Name = L"BackgroundHighlight";
			this->BackgroundHighlight->Size = System::Drawing::Size(493, 401);
			this->BackgroundHighlight->TabIndex = 7;
			this->BackgroundHighlight->UseCustomBackColor = true;
			// 
			// BottomInfoText
			// 
			this->BottomInfoText->BackColor = System::Drawing::Color::WhiteSmoke;
			this->BottomInfoText->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->BottomInfoText->Location = System::Drawing::Point(24, 534);
			this->BottomInfoText->Name = L"BottomInfoText";
			this->BottomInfoText->Size = System::Drawing::Size(493, 100);
			this->BottomInfoText->TabIndex = 8;
			this->BottomInfoText->Text = L"WebTrack is a demonstration of a better looking windows forms with the Metro Mode"
				L"rn UI.  WebTrack will ping your requested websites and display the status of you"
				L"r connection to them.";
			this->BottomInfoText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->BottomInfoText->UseCustomBackColor = true;
			this->BottomInfoText->UseCustomForeColor = true;
			this->BottomInfoText->UseStyleColors = true;
			this->BottomInfoText->WrapToLine = true;
			// 
			// ListTitle
			// 
			this->ListTitle->Location = System::Drawing::Point(68, 130);
			this->ListTitle->Name = L"ListTitle";
			this->ListTitle->Size = System::Drawing::Size(405, 41);
			this->ListTitle->TabIndex = 10;
			this->ListTitle->Text = L"Added Links";
			this->ListTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// InfoListView
			// 
			this->InfoListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->WebsiteURL, this->Status,
					this->Desc
			});
			this->InfoListView->Location = System::Drawing::Point(68, 184);
			this->InfoListView->Name = L"InfoListView";
			this->InfoListView->ShowItemToolTips = true;
			this->InfoListView->Size = System::Drawing::Size(405, 297);
			this->InfoListView->TabIndex = 11;
			this->InfoListView->UseCompatibleStateImageBehavior = false;
			this->InfoListView->View = System::Windows::Forms::View::Details;
			// 
			// WebsiteURL
			// 
			this->WebsiteURL->Text = L"Website URL";
			this->WebsiteURL->Width = 200;
			// 
			// Status
			// 
			this->Status->Text = L"Status";
			this->Status->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Status->Width = 100;
			// 
			// Desc
			// 
			this->Desc->Text = L"Desc";
			this->Desc->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Desc->Width = 100;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(540, 643);
			this->Controls->Add(this->InfoListView);
			this->Controls->Add(this->ListTitle);
			this->Controls->Add(this->BottomInfoText);
			this->Controls->Add(this->BackgroundHighlight);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->URLNameInput);
			this->Name = L"MyForm";
			this->Resizable = false;
			this->Text = L"WebTrack";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void metroTextBox1_Click(System::Object^  sender, System::EventArgs^  e) { 
	}
	public: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e);  //  Implementation in source.cpp
};
}
