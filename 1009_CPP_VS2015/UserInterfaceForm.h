#pragma once

namespace My1009_CPP_VS2015 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UserInterfaceForm
	/// </summary>
	public ref class UserInterfaceForm : public System::Windows::Forms::Form
	{
	public:
		UserInterfaceForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserInterfaceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  sidePanelBacking;
	private: System::Windows::Forms::PictureBox^  sitLogo;
	private: System::Windows::Forms::Label^  functionalitiesLabel;
	protected:

	protected:


	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  instagramTab;
	private: System::Windows::Forms::TabPage^  twitterTab;
	private: System::Windows::Forms::Button^  instagramButton;



	private: System::Windows::Forms::Label^  instagramHeaderLabel;
	private: System::Windows::Forms::Button^  twitterButton;


	private: System::Windows::Forms::Label^  twitterHeaderLabel;
	private: System::Windows::Forms::Button^  dataAnalysisButton;

	private: System::Windows::Forms::Button^  displayJsonButton;
	private: System::Windows::Forms::Button^  aboutButton;
	private: System::Windows::Forms::Label^  informationLabel;
	private: System::Windows::Forms::Button^  visualisationButton;
	private: System::Windows::Forms::TabPage^  displayJsonTab;
	private: System::Windows::Forms::Label^  displayJsonHeaderLabel;
	private: System::Windows::Forms::TabPage^  dataAnalysisTab;
	private: System::Windows::Forms::TabPage^  visualisationTab;
	private: System::Windows::Forms::TabPage^  aboutTab;
	private: System::Windows::Forms::Label^  dataAnalysisHeaderLabel;
	private: System::Windows::Forms::Label^  visualisationHeaderLabel;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UserInterfaceForm::typeid));
			this->sidePanelBacking = (gcnew System::Windows::Forms::Panel());
			this->aboutButton = (gcnew System::Windows::Forms::Button());
			this->informationLabel = (gcnew System::Windows::Forms::Label());
			this->visualisationButton = (gcnew System::Windows::Forms::Button());
			this->dataAnalysisButton = (gcnew System::Windows::Forms::Button());
			this->displayJsonButton = (gcnew System::Windows::Forms::Button());
			this->twitterButton = (gcnew System::Windows::Forms::Button());
			this->instagramButton = (gcnew System::Windows::Forms::Button());
			this->functionalitiesLabel = (gcnew System::Windows::Forms::Label());
			this->sitLogo = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->instagramTab = (gcnew System::Windows::Forms::TabPage());
			this->instagramHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->twitterTab = (gcnew System::Windows::Forms::TabPage());
			this->twitterHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->displayJsonTab = (gcnew System::Windows::Forms::TabPage());
			this->displayJsonHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->dataAnalysisTab = (gcnew System::Windows::Forms::TabPage());
			this->dataAnalysisHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->visualisationTab = (gcnew System::Windows::Forms::TabPage());
			this->visualisationHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->aboutTab = (gcnew System::Windows::Forms::TabPage());
			this->sidePanelBacking->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sitLogo))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->instagramTab->SuspendLayout();
			this->twitterTab->SuspendLayout();
			this->displayJsonTab->SuspendLayout();
			this->dataAnalysisTab->SuspendLayout();
			this->visualisationTab->SuspendLayout();
			this->SuspendLayout();
			// 
			// sidePanelBacking
			// 
			this->sidePanelBacking->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->sidePanelBacking->Controls->Add(this->aboutButton);
			this->sidePanelBacking->Controls->Add(this->informationLabel);
			this->sidePanelBacking->Controls->Add(this->visualisationButton);
			this->sidePanelBacking->Controls->Add(this->dataAnalysisButton);
			this->sidePanelBacking->Controls->Add(this->displayJsonButton);
			this->sidePanelBacking->Controls->Add(this->twitterButton);
			this->sidePanelBacking->Controls->Add(this->instagramButton);
			this->sidePanelBacking->Controls->Add(this->functionalitiesLabel);
			this->sidePanelBacking->Controls->Add(this->sitLogo);
			this->sidePanelBacking->Location = System::Drawing::Point(0, -1);
			this->sidePanelBacking->Name = L"sidePanelBacking";
			this->sidePanelBacking->Size = System::Drawing::Size(237, 633);
			this->sidePanelBacking->TabIndex = 0;
			// 
			// aboutButton
			// 
			this->aboutButton->BackColor = System::Drawing::Color::DimGray;
			this->aboutButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->aboutButton->FlatAppearance->BorderSize = 0;
			this->aboutButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->aboutButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->aboutButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->aboutButton->Location = System::Drawing::Point(-6, 526);
			this->aboutButton->Name = L"aboutButton";
			this->aboutButton->Size = System::Drawing::Size(237, 61);
			this->aboutButton->TabIndex = 8;
			this->aboutButton->Text = L"About";
			this->aboutButton->UseVisualStyleBackColor = false;
			this->aboutButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::aboutButton_Click);
			// 
			// informationLabel
			// 
			this->informationLabel->AutoSize = true;
			this->informationLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.14286F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->informationLabel->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->informationLabel->Location = System::Drawing::Point(12, 493);
			this->informationLabel->Name = L"informationLabel";
			this->informationLabel->Size = System::Drawing::Size(127, 30);
			this->informationLabel->TabIndex = 7;
			this->informationLabel->Text = L"Information";
			// 
			// visualisationButton
			// 
			this->visualisationButton->BackColor = System::Drawing::Color::DimGray;
			this->visualisationButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->visualisationButton->FlatAppearance->BorderSize = 0;
			this->visualisationButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->visualisationButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->visualisationButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->visualisationButton->Location = System::Drawing::Point(0, 417);
			this->visualisationButton->Name = L"visualisationButton";
			this->visualisationButton->Size = System::Drawing::Size(237, 61);
			this->visualisationButton->TabIndex = 6;
			this->visualisationButton->Text = L"Visualisation";
			this->visualisationButton->UseVisualStyleBackColor = false;
			this->visualisationButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::visualisationButton_Click);
			// 
			// dataAnalysisButton
			// 
			this->dataAnalysisButton->BackColor = System::Drawing::Color::DimGray;
			this->dataAnalysisButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->dataAnalysisButton->FlatAppearance->BorderSize = 0;
			this->dataAnalysisButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dataAnalysisButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->dataAnalysisButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataAnalysisButton->Location = System::Drawing::Point(0, 356);
			this->dataAnalysisButton->Name = L"dataAnalysisButton";
			this->dataAnalysisButton->Size = System::Drawing::Size(237, 61);
			this->dataAnalysisButton->TabIndex = 5;
			this->dataAnalysisButton->Text = L"Data Analysis";
			this->dataAnalysisButton->UseVisualStyleBackColor = false;
			this->dataAnalysisButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::dataAnalysisButton_Click);
			// 
			// displayJsonButton
			// 
			this->displayJsonButton->BackColor = System::Drawing::Color::DimGray;
			this->displayJsonButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->displayJsonButton->FlatAppearance->BorderSize = 0;
			this->displayJsonButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->displayJsonButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->displayJsonButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->displayJsonButton->Location = System::Drawing::Point(0, 295);
			this->displayJsonButton->Name = L"displayJsonButton";
			this->displayJsonButton->Size = System::Drawing::Size(237, 61);
			this->displayJsonButton->TabIndex = 4;
			this->displayJsonButton->Text = L"Display Json";
			this->displayJsonButton->UseVisualStyleBackColor = false;
			this->displayJsonButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::displayJsonButton_Click);
			// 
			// twitterButton
			// 
			this->twitterButton->BackColor = System::Drawing::Color::DimGray;
			this->twitterButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->twitterButton->FlatAppearance->BorderSize = 0;
			this->twitterButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->twitterButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->twitterButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->twitterButton->Location = System::Drawing::Point(0, 234);
			this->twitterButton->Name = L"twitterButton";
			this->twitterButton->Size = System::Drawing::Size(237, 61);
			this->twitterButton->TabIndex = 3;
			this->twitterButton->Text = L"Twitter";
			this->twitterButton->UseVisualStyleBackColor = false;
			this->twitterButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::twitterButton_Click);
			// 
			// instagramButton
			// 
			this->instagramButton->BackColor = System::Drawing::Color::DimGray;
			this->instagramButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->instagramButton->FlatAppearance->BorderSize = 0;
			this->instagramButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->instagramButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->instagramButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->instagramButton->Location = System::Drawing::Point(0, 173);
			this->instagramButton->Name = L"instagramButton";
			this->instagramButton->Size = System::Drawing::Size(237, 61);
			this->instagramButton->TabIndex = 2;
			this->instagramButton->Text = L"Instagram";
			this->instagramButton->UseVisualStyleBackColor = false;
			this->instagramButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::button1_Click);
			// 
			// functionalitiesLabel
			// 
			this->functionalitiesLabel->AutoSize = true;
			this->functionalitiesLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.14286F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->functionalitiesLabel->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->functionalitiesLabel->Location = System::Drawing::Point(12, 139);
			this->functionalitiesLabel->Name = L"functionalitiesLabel";
			this->functionalitiesLabel->Size = System::Drawing::Size(150, 30);
			this->functionalitiesLabel->TabIndex = 1;
			this->functionalitiesLabel->Text = L"Functionalities";
			// 
			// sitLogo
			// 
			this->sitLogo->BackColor = System::Drawing::Color::Gainsboro;
			this->sitLogo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sitLogo.Image")));
			this->sitLogo->Location = System::Drawing::Point(-11, 0);
			this->sitLogo->Name = L"sitLogo";
			this->sitLogo->Size = System::Drawing::Size(248, 127);
			this->sitLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->sitLogo->TabIndex = 0;
			this->sitLogo->TabStop = false;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->instagramTab);
			this->tabControl1->Controls->Add(this->twitterTab);
			this->tabControl1->Controls->Add(this->displayJsonTab);
			this->tabControl1->Controls->Add(this->dataAnalysisTab);
			this->tabControl1->Controls->Add(this->visualisationTab);
			this->tabControl1->Controls->Add(this->aboutTab);
			this->tabControl1->Location = System::Drawing::Point(233, -36);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(860, 668);
			this->tabControl1->TabIndex = 1;
			// 
			// instagramTab
			// 
			this->instagramTab->Controls->Add(this->instagramHeaderLabel);
			this->instagramTab->Location = System::Drawing::Point(4, 33);
			this->instagramTab->Name = L"instagramTab";
			this->instagramTab->Padding = System::Windows::Forms::Padding(3);
			this->instagramTab->Size = System::Drawing::Size(852, 631);
			this->instagramTab->TabIndex = 0;
			this->instagramTab->Text = L"1";
			this->instagramTab->UseVisualStyleBackColor = true;
			// 
			// instagramHeaderLabel
			// 
			this->instagramHeaderLabel->AutoSize = true;
			this->instagramHeaderLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->instagramHeaderLabel->Location = System::Drawing::Point(6, 10);
			this->instagramHeaderLabel->Name = L"instagramHeaderLabel";
			this->instagramHeaderLabel->Size = System::Drawing::Size(259, 31);
			this->instagramHeaderLabel->TabIndex = 0;
			this->instagramHeaderLabel->Text = L"Instagram Scraper";
			// 
			// twitterTab
			// 
			this->twitterTab->Controls->Add(this->twitterHeaderLabel);
			this->twitterTab->Location = System::Drawing::Point(4, 33);
			this->twitterTab->Name = L"twitterTab";
			this->twitterTab->Padding = System::Windows::Forms::Padding(3);
			this->twitterTab->Size = System::Drawing::Size(852, 632);
			this->twitterTab->TabIndex = 1;
			this->twitterTab->Text = L"2";
			this->twitterTab->UseVisualStyleBackColor = true;
			// 
			// twitterHeaderLabel
			// 
			this->twitterHeaderLabel->AutoSize = true;
			this->twitterHeaderLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->twitterHeaderLabel->Location = System::Drawing::Point(6, 10);
			this->twitterHeaderLabel->Name = L"twitterHeaderLabel";
			this->twitterHeaderLabel->Size = System::Drawing::Size(216, 31);
			this->twitterHeaderLabel->TabIndex = 0;
			this->twitterHeaderLabel->Text = L"Twitter Scraper";
			// 
			// displayJsonTab
			// 
			this->displayJsonTab->Controls->Add(this->displayJsonHeaderLabel);
			this->displayJsonTab->Location = System::Drawing::Point(4, 33);
			this->displayJsonTab->Name = L"displayJsonTab";
			this->displayJsonTab->Size = System::Drawing::Size(852, 632);
			this->displayJsonTab->TabIndex = 2;
			this->displayJsonTab->Text = L"3";
			this->displayJsonTab->UseVisualStyleBackColor = true;
			// 
			// displayJsonHeaderLabel
			// 
			this->displayJsonHeaderLabel->AutoSize = true;
			this->displayJsonHeaderLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->displayJsonHeaderLabel->Location = System::Drawing::Point(6, 10);
			this->displayJsonHeaderLabel->Name = L"displayJsonHeaderLabel";
			this->displayJsonHeaderLabel->Size = System::Drawing::Size(177, 31);
			this->displayJsonHeaderLabel->TabIndex = 0;
			this->displayJsonHeaderLabel->Text = L"Display Json";
			// 
			// dataAnalysisTab
			// 
			this->dataAnalysisTab->Controls->Add(this->dataAnalysisHeaderLabel);
			this->dataAnalysisTab->Location = System::Drawing::Point(4, 33);
			this->dataAnalysisTab->Name = L"dataAnalysisTab";
			this->dataAnalysisTab->Size = System::Drawing::Size(852, 632);
			this->dataAnalysisTab->TabIndex = 3;
			this->dataAnalysisTab->Text = L"4";
			this->dataAnalysisTab->UseVisualStyleBackColor = true;
			// 
			// dataAnalysisHeaderLabel
			// 
			this->dataAnalysisHeaderLabel->AutoSize = true;
			this->dataAnalysisHeaderLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->dataAnalysisHeaderLabel->Location = System::Drawing::Point(6, 10);
			this->dataAnalysisHeaderLabel->Name = L"dataAnalysisHeaderLabel";
			this->dataAnalysisHeaderLabel->Size = System::Drawing::Size(193, 31);
			this->dataAnalysisHeaderLabel->TabIndex = 0;
			this->dataAnalysisHeaderLabel->Text = L"Data Analysis";
			// 
			// visualisationTab
			// 
			this->visualisationTab->Controls->Add(this->visualisationHeaderLabel);
			this->visualisationTab->Location = System::Drawing::Point(4, 33);
			this->visualisationTab->Name = L"visualisationTab";
			this->visualisationTab->Size = System::Drawing::Size(852, 632);
			this->visualisationTab->TabIndex = 4;
			this->visualisationTab->Text = L"5";
			this->visualisationTab->UseVisualStyleBackColor = true;
			// 
			// visualisationHeaderLabel
			// 
			this->visualisationHeaderLabel->AutoSize = true;
			this->visualisationHeaderLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->visualisationHeaderLabel->Location = System::Drawing::Point(6, 10);
			this->visualisationHeaderLabel->Name = L"visualisationHeaderLabel";
			this->visualisationHeaderLabel->Size = System::Drawing::Size(183, 31);
			this->visualisationHeaderLabel->TabIndex = 0;
			this->visualisationHeaderLabel->Text = L"Visualisation";
			// 
			// aboutTab
			// 
			this->aboutTab->Location = System::Drawing::Point(4, 33);
			this->aboutTab->Name = L"aboutTab";
			this->aboutTab->Size = System::Drawing::Size(852, 632);
			this->aboutTab->TabIndex = 5;
			this->aboutTab->Text = L"6";
			this->aboutTab->UseVisualStyleBackColor = true;
			// 
			// UserInterfaceForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1092, 631);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->sidePanelBacking);
			this->Name = L"UserInterfaceForm";
			this->Text = L"UserInterfaceForm";
			this->sidePanelBacking->ResumeLayout(false);
			this->sidePanelBacking->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sitLogo))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->instagramTab->ResumeLayout(false);
			this->instagramTab->PerformLayout();
			this->twitterTab->ResumeLayout(false);
			this->twitterTab->PerformLayout();
			this->displayJsonTab->ResumeLayout(false);
			this->displayJsonTab->PerformLayout();
			this->dataAnalysisTab->ResumeLayout(false);
			this->dataAnalysisTab->PerformLayout();
			this->visualisationTab->ResumeLayout(false);
			this->visualisationTab->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(0);
	}
	private: System::Void twitterButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(1);
	}
	private: System::Void displayJsonButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(2);
	}
	private: System::Void dataAnalysisButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(3);
	}
	private: System::Void visualisationButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(4);
	}
	private: System::Void aboutButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(5);
	}
	};
}
