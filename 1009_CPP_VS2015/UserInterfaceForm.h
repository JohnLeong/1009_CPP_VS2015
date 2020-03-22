#pragma once
#include <string>
#include <iostream>
#include "InstagramScrapper.h"
#include "FileUtility.h"
#include "OCRUtility.h"
#define nullptr __nullptr
#include "json.hpp"
#undef nullptr

#include <msclr\marshal_cppstd.h>

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
	private: System::Windows::Forms::Label^  instagramUsernameLabel;


	private: System::Windows::Forms::TextBox^  instagramUsernamePasswordTextBox;

	private: System::Windows::Forms::TextBox^  instagramUsernameTextBox;


	private: System::Windows::Forms::Label^  instagramProfilesLabel;
	private: System::Windows::Forms::Label^  instagramHashTagsLabel;
	private: System::Windows::Forms::Label^  instagramProfileNumberOfPostLabel;
	private: System::Windows::Forms::Label^  instagramHashTagNumberOfPostLabel;
	private: System::Windows::Forms::Label^  instagramProfileModeLabel;
	private: System::Windows::Forms::Label^  instagramHashTagModeLabel;
	private: System::Windows::Forms::Label^  instagramPasswordLabel;
	private: System::Windows::Forms::TextBox^  instagramProfilesTextBox;

	private: System::Windows::Forms::TextBox^  instagramProfilePostCountTextBox;
	private: System::Windows::Forms::TextBox^  instagramHashTagsTextBox;


	private: System::Windows::Forms::TextBox^  instagramHashTagPostCountTextBox;
	private: System::Windows::Forms::Button^  instagramProfileExecuteButton;

	private: System::Windows::Forms::Button^  instagramHashTagExecuteButton;
	private: System::Windows::Forms::Button^  instagramBrowseExportFolderButton;
	private: System::Windows::Forms::Label^  instagramExportFolderPathLabel;
	private: System::Windows::Forms::Label^  instagramExportLabel;
	private: System::Windows::Forms::FolderBrowserDialog^  instagramFolderDialog;
	private: System::Windows::Forms::Label^  instagramExportFolderPathValueLabel;
	private: System::Windows::Forms::TextBox^  instagramConsole;
	private: System::Windows::Forms::Label^  displayJsonFilePathValueLabel;

	private: System::Windows::Forms::Button^  displayJsonSaveAsButton;
	private: System::Windows::Forms::Button^  displayJsonSelectJsonButton;
	private: System::Windows::Forms::Label^  displayJsonFilePathLabel;
	private: System::Windows::Forms::Label^  displayJsonFilePathHeaderLabel;
	private: System::Windows::Forms::OpenFileDialog^  displayJsonLoadFileDialog;
	private: System::Windows::Forms::RichTextBox^  displayJsonFileOutputRichTextBox;
	private: System::Windows::Forms::SaveFileDialog^  displayJsonSaveFileDialog;
	private: System::Windows::Forms::Button^  imageOcrButton;

	private: System::Windows::Forms::TabPage^  imageOcrTab;
	private: System::Windows::Forms::Label^  imageOcrHeaderLabel;
	private: System::Windows::Forms::Label^  imageOcrFilePathLabel;

	private: System::Windows::Forms::Label^  imageOcrDescriptionLabel;
	private: System::Windows::Forms::Label^  imageOcrFilePathHeaderLabel;
private: System::Windows::Forms::Label^  imageOcrFilePathValueLabel;
private: System::Windows::Forms::Button^  imageOcrExecuteButton;
private: System::Windows::Forms::TextBox^  imageOcrConsoleTextBox;
private: System::Windows::Forms::Button^  imageOcrBrowseJsonButton;
private: System::Windows::Forms::OpenFileDialog^  imageOcrLoadFileDialog;


























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
			this->imageOcrButton = (gcnew System::Windows::Forms::Button());
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
			this->instagramConsole = (gcnew System::Windows::Forms::TextBox());
			this->instagramExportFolderPathValueLabel = (gcnew System::Windows::Forms::Label());
			this->instagramBrowseExportFolderButton = (gcnew System::Windows::Forms::Button());
			this->instagramExportFolderPathLabel = (gcnew System::Windows::Forms::Label());
			this->instagramExportLabel = (gcnew System::Windows::Forms::Label());
			this->instagramProfileExecuteButton = (gcnew System::Windows::Forms::Button());
			this->instagramHashTagExecuteButton = (gcnew System::Windows::Forms::Button());
			this->instagramProfilesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instagramProfilePostCountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instagramHashTagsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instagramHashTagPostCountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instagramUsernamePasswordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instagramUsernameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instagramProfilesLabel = (gcnew System::Windows::Forms::Label());
			this->instagramHashTagsLabel = (gcnew System::Windows::Forms::Label());
			this->instagramProfileNumberOfPostLabel = (gcnew System::Windows::Forms::Label());
			this->instagramHashTagNumberOfPostLabel = (gcnew System::Windows::Forms::Label());
			this->instagramProfileModeLabel = (gcnew System::Windows::Forms::Label());
			this->instagramHashTagModeLabel = (gcnew System::Windows::Forms::Label());
			this->instagramPasswordLabel = (gcnew System::Windows::Forms::Label());
			this->instagramUsernameLabel = (gcnew System::Windows::Forms::Label());
			this->instagramHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->twitterTab = (gcnew System::Windows::Forms::TabPage());
			this->twitterHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->displayJsonTab = (gcnew System::Windows::Forms::TabPage());
			this->displayJsonFileOutputRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->displayJsonFilePathValueLabel = (gcnew System::Windows::Forms::Label());
			this->displayJsonSaveAsButton = (gcnew System::Windows::Forms::Button());
			this->displayJsonSelectJsonButton = (gcnew System::Windows::Forms::Button());
			this->displayJsonFilePathLabel = (gcnew System::Windows::Forms::Label());
			this->displayJsonFilePathHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->displayJsonHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->dataAnalysisTab = (gcnew System::Windows::Forms::TabPage());
			this->dataAnalysisHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->visualisationTab = (gcnew System::Windows::Forms::TabPage());
			this->visualisationHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->imageOcrTab = (gcnew System::Windows::Forms::TabPage());
			this->imageOcrExecuteButton = (gcnew System::Windows::Forms::Button());
			this->imageOcrConsoleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->imageOcrBrowseJsonButton = (gcnew System::Windows::Forms::Button());
			this->imageOcrFilePathHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->imageOcrFilePathValueLabel = (gcnew System::Windows::Forms::Label());
			this->imageOcrFilePathLabel = (gcnew System::Windows::Forms::Label());
			this->imageOcrDescriptionLabel = (gcnew System::Windows::Forms::Label());
			this->imageOcrHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->aboutTab = (gcnew System::Windows::Forms::TabPage());
			this->instagramFolderDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->displayJsonLoadFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->displayJsonSaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->imageOcrLoadFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->sidePanelBacking->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sitLogo))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->instagramTab->SuspendLayout();
			this->twitterTab->SuspendLayout();
			this->displayJsonTab->SuspendLayout();
			this->dataAnalysisTab->SuspendLayout();
			this->visualisationTab->SuspendLayout();
			this->imageOcrTab->SuspendLayout();
			this->SuspendLayout();
			// 
			// sidePanelBacking
			// 
			this->sidePanelBacking->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->sidePanelBacking->Controls->Add(this->imageOcrButton);
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
			this->sidePanelBacking->Size = System::Drawing::Size(237, 681);
			this->sidePanelBacking->TabIndex = 0;
			// 
			// imageOcrButton
			// 
			this->imageOcrButton->BackColor = System::Drawing::Color::DimGray;
			this->imageOcrButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->imageOcrButton->FlatAppearance->BorderSize = 0;
			this->imageOcrButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->imageOcrButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->imageOcrButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->imageOcrButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imageOcrButton.Image")));
			this->imageOcrButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->imageOcrButton->Location = System::Drawing::Point(-3, 473);
			this->imageOcrButton->Name = L"imageOcrButton";
			this->imageOcrButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
			this->imageOcrButton->Size = System::Drawing::Size(237, 61);
			this->imageOcrButton->TabIndex = 9;
			this->imageOcrButton->Text = L"Image OCR";
			this->imageOcrButton->UseVisualStyleBackColor = false;
			this->imageOcrButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::imageOcrButton_Click);
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
			this->aboutButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutButton.Image")));
			this->aboutButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->aboutButton->Location = System::Drawing::Point(-3, 570);
			this->aboutButton->Name = L"aboutButton";
			this->aboutButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
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
			this->informationLabel->Location = System::Drawing::Point(12, 537);
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
			this->visualisationButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"visualisationButton.Image")));
			this->visualisationButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->visualisationButton->Location = System::Drawing::Point(0, 417);
			this->visualisationButton->Name = L"visualisationButton";
			this->visualisationButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
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
			this->dataAnalysisButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dataAnalysisButton.Image")));
			this->dataAnalysisButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->dataAnalysisButton->Location = System::Drawing::Point(0, 356);
			this->dataAnalysisButton->Name = L"dataAnalysisButton";
			this->dataAnalysisButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
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
			this->displayJsonButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"displayJsonButton.Image")));
			this->displayJsonButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->displayJsonButton->Location = System::Drawing::Point(0, 286);
			this->displayJsonButton->Name = L"displayJsonButton";
			this->displayJsonButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
			this->displayJsonButton->Size = System::Drawing::Size(237, 70);
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
			this->twitterButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"twitterButton.Image")));
			this->twitterButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->twitterButton->Location = System::Drawing::Point(0, 234);
			this->twitterButton->Name = L"twitterButton";
			this->twitterButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
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
			this->instagramButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"instagramButton.Image")));
			this->instagramButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->instagramButton->Location = System::Drawing::Point(0, 173);
			this->instagramButton->Name = L"instagramButton";
			this->instagramButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
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
			this->tabControl1->Controls->Add(this->imageOcrTab);
			this->tabControl1->Controls->Add(this->aboutTab);
			this->tabControl1->Location = System::Drawing::Point(233, -36);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(860, 746);
			this->tabControl1->TabIndex = 1;
			// 
			// instagramTab
			// 
			this->instagramTab->Controls->Add(this->instagramConsole);
			this->instagramTab->Controls->Add(this->instagramExportFolderPathValueLabel);
			this->instagramTab->Controls->Add(this->instagramBrowseExportFolderButton);
			this->instagramTab->Controls->Add(this->instagramExportFolderPathLabel);
			this->instagramTab->Controls->Add(this->instagramExportLabel);
			this->instagramTab->Controls->Add(this->instagramProfileExecuteButton);
			this->instagramTab->Controls->Add(this->instagramHashTagExecuteButton);
			this->instagramTab->Controls->Add(this->instagramProfilesTextBox);
			this->instagramTab->Controls->Add(this->instagramProfilePostCountTextBox);
			this->instagramTab->Controls->Add(this->instagramHashTagsTextBox);
			this->instagramTab->Controls->Add(this->instagramHashTagPostCountTextBox);
			this->instagramTab->Controls->Add(this->instagramUsernamePasswordTextBox);
			this->instagramTab->Controls->Add(this->instagramUsernameTextBox);
			this->instagramTab->Controls->Add(this->instagramProfilesLabel);
			this->instagramTab->Controls->Add(this->instagramHashTagsLabel);
			this->instagramTab->Controls->Add(this->instagramProfileNumberOfPostLabel);
			this->instagramTab->Controls->Add(this->instagramHashTagNumberOfPostLabel);
			this->instagramTab->Controls->Add(this->instagramProfileModeLabel);
			this->instagramTab->Controls->Add(this->instagramHashTagModeLabel);
			this->instagramTab->Controls->Add(this->instagramPasswordLabel);
			this->instagramTab->Controls->Add(this->instagramUsernameLabel);
			this->instagramTab->Controls->Add(this->instagramHeaderLabel);
			this->instagramTab->Location = System::Drawing::Point(12, 58);
			this->instagramTab->Name = L"instagramTab";
			this->instagramTab->Padding = System::Windows::Forms::Padding(3);
			this->instagramTab->Size = System::Drawing::Size(836, 676);
			this->instagramTab->TabIndex = 0;
			this->instagramTab->Text = L"1";
			this->instagramTab->UseVisualStyleBackColor = true;
			// 
			// instagramConsole
			// 
			this->instagramConsole->Location = System::Drawing::Point(52, 514);
			this->instagramConsole->Multiline = true;
			this->instagramConsole->Name = L"instagramConsole";
			this->instagramConsole->ReadOnly = true;
			this->instagramConsole->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->instagramConsole->Size = System::Drawing::Size(686, 83);
			this->instagramConsole->TabIndex = 22;
			// 
			// instagramExportFolderPathValueLabel
			// 
			this->instagramExportFolderPathValueLabel->AutoSize = true;
			this->instagramExportFolderPathValueLabel->Location = System::Drawing::Point(275, 120);
			this->instagramExportFolderPathValueLabel->Name = L"instagramExportFolderPathValueLabel";
			this->instagramExportFolderPathValueLabel->Size = System::Drawing::Size(94, 37);
			this->instagramExportFolderPathValueLabel->TabIndex = 21;
			this->instagramExportFolderPathValueLabel->Text = L"None";
			// 
			// instagramBrowseExportFolderButton
			// 
			this->instagramBrowseExportFolderButton->Location = System::Drawing::Point(39, 170);
			this->instagramBrowseExportFolderButton->Name = L"instagramBrowseExportFolderButton";
			this->instagramBrowseExportFolderButton->Size = System::Drawing::Size(101, 28);
			this->instagramBrowseExportFolderButton->TabIndex = 20;
			this->instagramBrowseExportFolderButton->Text = L"Select folder path";
			this->instagramBrowseExportFolderButton->UseVisualStyleBackColor = true;
			this->instagramBrowseExportFolderButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramBrowseExportFolderButton_Click);
			// 
			// instagramExportFolderPathLabel
			// 
			this->instagramExportFolderPathLabel->AutoSize = true;
			this->instagramExportFolderPathLabel->Location = System::Drawing::Point(25, 130);
			this->instagramExportFolderPathLabel->Name = L"instagramExportFolderPathLabel";
			this->instagramExportFolderPathLabel->Size = System::Drawing::Size(201, 37);
			this->instagramExportFolderPathLabel->TabIndex = 19;
			this->instagramExportFolderPathLabel->Text = L"Folder Path: ";
			// 
			// instagramExportLabel
			// 
			this->instagramExportLabel->AutoSize = true;
			this->instagramExportLabel->Location = System::Drawing::Point(25, 93);
			this->instagramExportLabel->Name = L"instagramExportLabel";
			this->instagramExportLabel->Size = System::Drawing::Size(218, 37);
			this->instagramExportLabel->TabIndex = 19;
			this->instagramExportLabel->Text = L"Export Folder:";
			// 
			// instagramProfileExecuteButton
			// 
			this->instagramProfileExecuteButton->Location = System::Drawing::Point(399, 458);
			this->instagramProfileExecuteButton->Name = L"instagramProfileExecuteButton";
			this->instagramProfileExecuteButton->Size = System::Drawing::Size(150, 35);
			this->instagramProfileExecuteButton->TabIndex = 18;
			this->instagramProfileExecuteButton->Text = L"Execute";
			this->instagramProfileExecuteButton->UseVisualStyleBackColor = true;
			this->instagramProfileExecuteButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramProfileExecuteButton_Click);
			// 
			// instagramHashTagExecuteButton
			// 
			this->instagramHashTagExecuteButton->Location = System::Drawing::Point(39, 458);
			this->instagramHashTagExecuteButton->Name = L"instagramHashTagExecuteButton";
			this->instagramHashTagExecuteButton->Size = System::Drawing::Size(150, 35);
			this->instagramHashTagExecuteButton->TabIndex = 17;
			this->instagramHashTagExecuteButton->Text = L"Execute";
			this->instagramHashTagExecuteButton->UseVisualStyleBackColor = true;
			this->instagramHashTagExecuteButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramHashTagExecuteButton_Click);
			// 
			// instagramProfilesTextBox
			// 
			this->instagramProfilesTextBox->Location = System::Drawing::Point(399, 382);
			this->instagramProfilesTextBox->Multiline = true;
			this->instagramProfilesTextBox->Name = L"instagramProfilesTextBox";
			this->instagramProfilesTextBox->Size = System::Drawing::Size(200, 70);
			this->instagramProfilesTextBox->TabIndex = 16;
			this->instagramProfilesTextBox->TextChanged += gcnew System::EventHandler(this, &UserInterfaceForm::textBox8_TextChanged);
			// 
			// instagramProfilePostCountTextBox
			// 
			this->instagramProfilePostCountTextBox->Location = System::Drawing::Point(399, 284);
			this->instagramProfilePostCountTextBox->Name = L"instagramProfilePostCountTextBox";
			this->instagramProfilePostCountTextBox->Size = System::Drawing::Size(126, 44);
			this->instagramProfilePostCountTextBox->TabIndex = 15;
			// 
			// instagramHashTagsTextBox
			// 
			this->instagramHashTagsTextBox->Location = System::Drawing::Point(32, 382);
			this->instagramHashTagsTextBox->Multiline = true;
			this->instagramHashTagsTextBox->Name = L"instagramHashTagsTextBox";
			this->instagramHashTagsTextBox->Size = System::Drawing::Size(200, 70);
			this->instagramHashTagsTextBox->TabIndex = 14;
			// 
			// instagramHashTagPostCountTextBox
			// 
			this->instagramHashTagPostCountTextBox->Location = System::Drawing::Point(32, 284);
			this->instagramHashTagPostCountTextBox->Name = L"instagramHashTagPostCountTextBox";
			this->instagramHashTagPostCountTextBox->Size = System::Drawing::Size(126, 44);
			this->instagramHashTagPostCountTextBox->TabIndex = 13;
			// 
			// instagramUsernamePasswordTextBox
			// 
			this->instagramUsernamePasswordTextBox->Location = System::Drawing::Point(556, 56);
			this->instagramUsernamePasswordTextBox->Name = L"instagramUsernamePasswordTextBox";
			this->instagramUsernamePasswordTextBox->PasswordChar = '*';
			this->instagramUsernamePasswordTextBox->Size = System::Drawing::Size(126, 44);
			this->instagramUsernamePasswordTextBox->TabIndex = 10;
			this->instagramUsernamePasswordTextBox->Text = L"Password12345";
			// 
			// instagramUsernameTextBox
			// 
			this->instagramUsernameTextBox->Location = System::Drawing::Point(204, 62);
			this->instagramUsernameTextBox->Name = L"instagramUsernameTextBox";
			this->instagramUsernameTextBox->Size = System::Drawing::Size(126, 44);
			this->instagramUsernameTextBox->TabIndex = 9;
			this->instagramUsernameTextBox->Text = L"hehebongesher";
			// 
			// instagramProfilesLabel
			// 
			this->instagramProfilesLabel->AutoSize = true;
			this->instagramProfilesLabel->Location = System::Drawing::Point(392, 333);
			this->instagramProfilesLabel->Name = L"instagramProfilesLabel";
			this->instagramProfilesLabel->Size = System::Drawing::Size(123, 37);
			this->instagramProfilesLabel->TabIndex = 8;
			this->instagramProfilesLabel->Text = L"Profiles";
			this->instagramProfilesLabel->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramProfilesLabel_Click);
			// 
			// instagramHashTagsLabel
			// 
			this->instagramHashTagsLabel->AutoSize = true;
			this->instagramHashTagsLabel->Location = System::Drawing::Point(25, 333);
			this->instagramHashTagsLabel->Name = L"instagramHashTagsLabel";
			this->instagramHashTagsLabel->Size = System::Drawing::Size(164, 37);
			this->instagramHashTagsLabel->TabIndex = 7;
			this->instagramHashTagsLabel->Text = L"HashTags";
			// 
			// instagramProfileNumberOfPostLabel
			// 
			this->instagramProfileNumberOfPostLabel->AutoSize = true;
			this->instagramProfileNumberOfPostLabel->Location = System::Drawing::Point(392, 248);
			this->instagramProfileNumberOfPostLabel->Name = L"instagramProfileNumberOfPostLabel";
			this->instagramProfileNumberOfPostLabel->Size = System::Drawing::Size(257, 37);
			this->instagramProfileNumberOfPostLabel->TabIndex = 6;
			this->instagramProfileNumberOfPostLabel->Text = L"Number of Posts";
			// 
			// instagramHashTagNumberOfPostLabel
			// 
			this->instagramHashTagNumberOfPostLabel->AutoSize = true;
			this->instagramHashTagNumberOfPostLabel->Location = System::Drawing::Point(25, 248);
			this->instagramHashTagNumberOfPostLabel->Name = L"instagramHashTagNumberOfPostLabel";
			this->instagramHashTagNumberOfPostLabel->Size = System::Drawing::Size(257, 37);
			this->instagramHashTagNumberOfPostLabel->TabIndex = 5;
			this->instagramHashTagNumberOfPostLabel->Text = L"Number of Posts";
			// 
			// instagramProfileModeLabel
			// 
			this->instagramProfileModeLabel->AutoSize = true;
			this->instagramProfileModeLabel->Location = System::Drawing::Point(392, 201);
			this->instagramProfileModeLabel->Name = L"instagramProfileModeLabel";
			this->instagramProfileModeLabel->Size = System::Drawing::Size(195, 37);
			this->instagramProfileModeLabel->TabIndex = 4;
			this->instagramProfileModeLabel->Text = L"Profile Mode";
			// 
			// instagramHashTagModeLabel
			// 
			this->instagramHashTagModeLabel->AutoSize = true;
			this->instagramHashTagModeLabel->Location = System::Drawing::Point(25, 201);
			this->instagramHashTagModeLabel->Name = L"instagramHashTagModeLabel";
			this->instagramHashTagModeLabel->Size = System::Drawing::Size(236, 37);
			this->instagramHashTagModeLabel->TabIndex = 3;
			this->instagramHashTagModeLabel->Text = L"HashTag Mode";
			// 
			// instagramPasswordLabel
			// 
			this->instagramPasswordLabel->AutoSize = true;
			this->instagramPasswordLabel->Location = System::Drawing::Point(362, 56);
			this->instagramPasswordLabel->Name = L"instagramPasswordLabel";
			this->instagramPasswordLabel->Size = System::Drawing::Size(167, 37);
			this->instagramPasswordLabel->TabIndex = 2;
			this->instagramPasswordLabel->Text = L"Password:";
			// 
			// instagramUsernameLabel
			// 
			this->instagramUsernameLabel->AutoSize = true;
			this->instagramUsernameLabel->Location = System::Drawing::Point(25, 56);
			this->instagramUsernameLabel->Name = L"instagramUsernameLabel";
			this->instagramUsernameLabel->Size = System::Drawing::Size(173, 37);
			this->instagramUsernameLabel->TabIndex = 1;
			this->instagramUsernameLabel->Text = L"Username:";
			this->instagramUsernameLabel->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramUsernameLabel_Click);
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
			this->twitterTab->Location = System::Drawing::Point(12, 58);
			this->twitterTab->Name = L"twitterTab";
			this->twitterTab->Padding = System::Windows::Forms::Padding(3);
			this->twitterTab->Size = System::Drawing::Size(836, 676);
			this->twitterTab->TabIndex = 2;
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
			this->displayJsonTab->Controls->Add(this->displayJsonFileOutputRichTextBox);
			this->displayJsonTab->Controls->Add(this->displayJsonFilePathValueLabel);
			this->displayJsonTab->Controls->Add(this->displayJsonSaveAsButton);
			this->displayJsonTab->Controls->Add(this->displayJsonSelectJsonButton);
			this->displayJsonTab->Controls->Add(this->displayJsonFilePathLabel);
			this->displayJsonTab->Controls->Add(this->displayJsonFilePathHeaderLabel);
			this->displayJsonTab->Controls->Add(this->displayJsonHeaderLabel);
			this->displayJsonTab->Location = System::Drawing::Point(12, 58);
			this->displayJsonTab->Name = L"displayJsonTab";
			this->displayJsonTab->Size = System::Drawing::Size(836, 676);
			this->displayJsonTab->TabIndex = 3;
			this->displayJsonTab->Text = L"3";
			this->displayJsonTab->UseVisualStyleBackColor = true;
			// 
			// displayJsonFileOutputRichTextBox
			// 
			this->displayJsonFileOutputRichTextBox->Location = System::Drawing::Point(54, 250);
			this->displayJsonFileOutputRichTextBox->Name = L"displayJsonFileOutputRichTextBox";
			this->displayJsonFileOutputRichTextBox->Size = System::Drawing::Size(744, 313);
			this->displayJsonFileOutputRichTextBox->TabIndex = 6;
			this->displayJsonFileOutputRichTextBox->Text = L"";
			// 
			// displayJsonFilePathValueLabel
			// 
			this->displayJsonFilePathValueLabel->AutoSize = true;
			this->displayJsonFilePathValueLabel->Location = System::Drawing::Point(100, 150);
			this->displayJsonFilePathValueLabel->Name = L"displayJsonFilePathValueLabel";
			this->displayJsonFilePathValueLabel->Size = System::Drawing::Size(94, 37);
			this->displayJsonFilePathValueLabel->TabIndex = 5;
			this->displayJsonFilePathValueLabel->Text = L"None";
			// 
			// displayJsonSaveAsButton
			// 
			this->displayJsonSaveAsButton->Location = System::Drawing::Point(250, 200);
			this->displayJsonSaveAsButton->Name = L"displayJsonSaveAsButton";
			this->displayJsonSaveAsButton->Size = System::Drawing::Size(108, 45);
			this->displayJsonSaveAsButton->TabIndex = 4;
			this->displayJsonSaveAsButton->Text = L"Save As";
			this->displayJsonSaveAsButton->UseVisualStyleBackColor = true;
			this->displayJsonSaveAsButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::displayJsonSaveAsButton_Click);
			// 
			// displayJsonSelectJsonButton
			// 
			this->displayJsonSelectJsonButton->Location = System::Drawing::Point(75, 200);
			this->displayJsonSelectJsonButton->Name = L"displayJsonSelectJsonButton";
			this->displayJsonSelectJsonButton->Size = System::Drawing::Size(108, 45);
			this->displayJsonSelectJsonButton->TabIndex = 3;
			this->displayJsonSelectJsonButton->Text = L"Select file";
			this->displayJsonSelectJsonButton->UseVisualStyleBackColor = true;
			this->displayJsonSelectJsonButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::displayJsonSelectJsonButton_Click);
			// 
			// displayJsonFilePathLabel
			// 
			this->displayJsonFilePathLabel->AutoSize = true;
			this->displayJsonFilePathLabel->Location = System::Drawing::Point(48, 150);
			this->displayJsonFilePathLabel->Name = L"displayJsonFilePathLabel";
			this->displayJsonFilePathLabel->Size = System::Drawing::Size(100, 37);
			this->displayJsonFilePathLabel->TabIndex = 2;
			this->displayJsonFilePathLabel->Text = L"label1";
			// 
			// displayJsonFilePathHeaderLabel
			// 
			this->displayJsonFilePathHeaderLabel->AutoSize = true;
			this->displayJsonFilePathHeaderLabel->Location = System::Drawing::Point(48, 100);
			this->displayJsonFilePathHeaderLabel->Name = L"displayJsonFilePathHeaderLabel";
			this->displayJsonFilePathHeaderLabel->Size = System::Drawing::Size(229, 37);
			this->displayJsonFilePathHeaderLabel->TabIndex = 1;
			this->displayJsonFilePathHeaderLabel->Text = L"Json File Path:";
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
			this->dataAnalysisTab->Location = System::Drawing::Point(12, 58);
			this->dataAnalysisTab->Name = L"dataAnalysisTab";
			this->dataAnalysisTab->Size = System::Drawing::Size(836, 676);
			this->dataAnalysisTab->TabIndex = 4;
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
			this->visualisationTab->Location = System::Drawing::Point(12, 58);
			this->visualisationTab->Name = L"visualisationTab";
			this->visualisationTab->Size = System::Drawing::Size(836, 676);
			this->visualisationTab->TabIndex = 5;
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
			// imageOcrTab
			// 
			this->imageOcrTab->Controls->Add(this->imageOcrExecuteButton);
			this->imageOcrTab->Controls->Add(this->imageOcrConsoleTextBox);
			this->imageOcrTab->Controls->Add(this->imageOcrBrowseJsonButton);
			this->imageOcrTab->Controls->Add(this->imageOcrFilePathHeaderLabel);
			this->imageOcrTab->Controls->Add(this->imageOcrFilePathValueLabel);
			this->imageOcrTab->Controls->Add(this->imageOcrFilePathLabel);
			this->imageOcrTab->Controls->Add(this->imageOcrDescriptionLabel);
			this->imageOcrTab->Controls->Add(this->imageOcrHeaderLabel);
			this->imageOcrTab->Location = System::Drawing::Point(12, 58);
			this->imageOcrTab->Name = L"imageOcrTab";
			this->imageOcrTab->Size = System::Drawing::Size(836, 676);
			this->imageOcrTab->TabIndex = 6;
			this->imageOcrTab->Text = L"6";
			this->imageOcrTab->UseVisualStyleBackColor = true;
			// 
			// imageOcrExecuteButton
			// 
			this->imageOcrExecuteButton->Location = System::Drawing::Point(223, 277);
			this->imageOcrExecuteButton->Name = L"imageOcrExecuteButton";
			this->imageOcrExecuteButton->Size = System::Drawing::Size(75, 56);
			this->imageOcrExecuteButton->TabIndex = 7;
			this->imageOcrExecuteButton->Text = L"Execute";
			this->imageOcrExecuteButton->UseVisualStyleBackColor = true;
			this->imageOcrExecuteButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::imageOcrExecuteButton_Click);
			// 
			// imageOcrConsoleTextBox
			// 
			this->imageOcrConsoleTextBox->Location = System::Drawing::Point(56, 406);
			this->imageOcrConsoleTextBox->Multiline = true;
			this->imageOcrConsoleTextBox->Name = L"imageOcrConsoleTextBox";
			this->imageOcrConsoleTextBox->ReadOnly = true;
			this->imageOcrConsoleTextBox->Size = System::Drawing::Size(705, 225);
			this->imageOcrConsoleTextBox->TabIndex = 6;
			// 
			// imageOcrBrowseJsonButton
			// 
			this->imageOcrBrowseJsonButton->Location = System::Drawing::Point(53, 280);
			this->imageOcrBrowseJsonButton->Name = L"imageOcrBrowseJsonButton";
			this->imageOcrBrowseJsonButton->Size = System::Drawing::Size(75, 23);
			this->imageOcrBrowseJsonButton->TabIndex = 5;
			this->imageOcrBrowseJsonButton->Text = L"Browse";
			this->imageOcrBrowseJsonButton->UseVisualStyleBackColor = true;
			this->imageOcrBrowseJsonButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::imageOcrBrowseJsonButton_Click);
			// 
			// imageOcrFilePathHeaderLabel
			// 
			this->imageOcrFilePathHeaderLabel->AutoSize = true;
			this->imageOcrFilePathHeaderLabel->Location = System::Drawing::Point(50, 130);
			this->imageOcrFilePathHeaderLabel->Name = L"imageOcrFilePathHeaderLabel";
			this->imageOcrFilePathHeaderLabel->Size = System::Drawing::Size(208, 37);
			this->imageOcrFilePathHeaderLabel->TabIndex = 4;
			this->imageOcrFilePathHeaderLabel->Text = L"File Location:";
			// 
			// imageOcrFilePathValueLabel
			// 
			this->imageOcrFilePathValueLabel->AutoSize = true;
			this->imageOcrFilePathValueLabel->Location = System::Drawing::Point(150, 200);
			this->imageOcrFilePathValueLabel->Name = L"imageOcrFilePathValueLabel";
			this->imageOcrFilePathValueLabel->Size = System::Drawing::Size(94, 37);
			this->imageOcrFilePathValueLabel->TabIndex = 3;
			this->imageOcrFilePathValueLabel->Text = L"None";
			// 
			// imageOcrFilePathLabel
			// 
			this->imageOcrFilePathLabel->AutoSize = true;
			this->imageOcrFilePathLabel->Location = System::Drawing::Point(50, 200);
			this->imageOcrFilePathLabel->Name = L"imageOcrFilePathLabel";
			this->imageOcrFilePathLabel->Size = System::Drawing::Size(182, 37);
			this->imageOcrFilePathLabel->TabIndex = 2;
			this->imageOcrFilePathLabel->Text = L"File loaded:";
			// 
			// imageOcrDescriptionLabel
			// 
			this->imageOcrDescriptionLabel->AutoSize = true;
			this->imageOcrDescriptionLabel->Location = System::Drawing::Point(44, 73);
			this->imageOcrDescriptionLabel->Name = L"imageOcrDescriptionLabel";
			this->imageOcrDescriptionLabel->Size = System::Drawing::Size(2555, 37);
			this->imageOcrDescriptionLabel->TabIndex = 1;
			this->imageOcrDescriptionLabel->Text = L"*This function is currently only compatible with Instagram scraped Data. For ever"
				L"y post in the JSON file, an ocr_text field will be appended to it whenever text "
				L"extraction is possible. ";
			// 
			// imageOcrHeaderLabel
			// 
			this->imageOcrHeaderLabel->AutoSize = true;
			this->imageOcrHeaderLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->imageOcrHeaderLabel->Location = System::Drawing::Point(6, 10);
			this->imageOcrHeaderLabel->Name = L"imageOcrHeaderLabel";
			this->imageOcrHeaderLabel->Size = System::Drawing::Size(163, 31);
			this->imageOcrHeaderLabel->TabIndex = 0;
			this->imageOcrHeaderLabel->Text = L"Image OCR";
			// 
			// aboutTab
			// 
			this->aboutTab->Location = System::Drawing::Point(12, 58);
			this->aboutTab->Name = L"aboutTab";
			this->aboutTab->Size = System::Drawing::Size(836, 676);
			this->aboutTab->TabIndex = 7;
			this->aboutTab->Text = L"7";
			this->aboutTab->UseVisualStyleBackColor = true;
			// 
			// imageOcrLoadFileDialog
			// 
			this->imageOcrLoadFileDialog->FileName = L"openFileDialog1";
			// 
			// UserInterfaceForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1080, 679);
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
			this->imageOcrTab->ResumeLayout(false);
			this->imageOcrTab->PerformLayout();
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
	private: System::Void imageOcrButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->tabControl1->SelectTab(5);
	}
	private: System::Void aboutButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(6);
	}
	private: System::Void instagramUsernameLabel_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void instagramProfilesLabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void folderBrowserDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {
}
	private: System::Void instagramBrowseExportFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (instagramFolderDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			instagramExportFolderPathValueLabel->Text = instagramFolderDialog->SelectedPath;

		}
	}
	private: System::Void instagramHashTagExecuteButton_Click(System::Object^  sender, System::EventArgs^  e) {
		//Check user name whether keyed in,
		//Check whether password keyed in
		//Check if numberof post in hashtag is correfct (empty and is number)
		//check if hashtags is correct
		//Check if export path has been chosen
		bool success = true;
		using std::cout;
		using std::endl;

	/*	instagramConsole->AppendText(instagramExportFolderPathValueLabel->Text+"\r\n");
		instagramConsole->AppendText(instagramUsernameTextBox->Text+"\r\n");
		instagramConsole->AppendText(instagramUsernamePasswordTextBox->Text+"\r\n");*/

		if (instagramExportFolderPathValueLabel->Text == "None") {
			instagramConsole->AppendText("*Please choose an export path\r\n");
			success = false;
		}

		//Check for valid fields
		if (instagramUsernameTextBox->Text == "") {

			instagramConsole->AppendText("*Please enter username\r\n");
			success = false;
		}
		if (instagramUsernamePasswordTextBox->Text == "") {
			instagramConsole->AppendText("*Please enter password\r\n");
			success = false;
		}
		if (instagramHashTagPostCountTextBox->Text == "") {
			instagramConsole->AppendText("*Please enter number of posts\r\n");
			success = false;
		}
		try {
			double nubmerOfPost = double::Parse(instagramHashTagPostCountTextBox->Text);
		} catch (...) {
			instagramConsole->AppendText("*Invalid number of posts\r\n");
			success = false;
		}

		if (instagramHashTagsTextBox->Text == "") {
			instagramConsole->AppendText("*Please enter hashtags\r\n");
			success = false;
		}

		if (success) {
			std::string username = msclr::interop::marshal_as<std::string>(instagramUsernameTextBox->Text);
			std::string password =  msclr::interop::marshal_as<std::string>(instagramUsernamePasswordTextBox->Text);
			std::string hashtags = msclr::interop::marshal_as<std::string>(instagramHashTagsTextBox->Text);
			double postCap = System::Convert::ToDouble(instagramHashTagPostCountTextBox->Text);
			std::string exportFolderPath = msclr::interop::marshal_as<std::string>(instagramExportFolderPathValueLabel->Text);
			using ICT1009::WebScrapping::InstagramScrapper;
			typedef std::shared_ptr<InstagramScrapper> InstagramScrapperPtr;
			InstagramScrapperPtr scrapper(new InstagramScrapper);
			instagramConsole->AppendText("*Executing hashtag scraping procedure...\r\n");
			try {
				if (scrapper->scrapeByHashTags(username, password, hashtags, postCap, exportFolderPath) == 1) 
					instagramConsole->AppendText("*Finished hashtag scrapping procedure. \r\n");
			} catch (...) {
				instagramConsole->AppendText("*Error occured during hashtag scraping procedure...\r\n");
			}
		}
	}

	private: System::Void instagramProfileExecuteButton_Click(System::Object^  sender, System::EventArgs^  e) {

		bool success = true;
		using std::cout; using std::endl;

		if (instagramExportFolderPathValueLabel->Text == "None") {
			instagramConsole->AppendText("*Please choose an export path\r\n");
			success = false;
		}

		//Check for valid fields
		if (instagramUsernameTextBox->Text == "") {

			instagramConsole->AppendText("*Please enter username\r\n");
			success = false;
		}
		if (instagramUsernamePasswordTextBox->Text == "") {
			instagramConsole->AppendText("*Please enter password\r\n");
			success = false;
		}
		if (instagramProfilePostCountTextBox->Text == "") {
			instagramConsole->AppendText("*Please enter number of posts\r\n");
			success = false;
		}
		try {
			double nubmerOfPost = double::Parse(instagramProfilePostCountTextBox->Text);
		} catch (...) {
			instagramConsole->AppendText("*Invalid number of posts\r\n");
			success = false;
		}

		if (instagramProfilesTextBox->Text == "") {
			instagramConsole->AppendText("*Please enter profiles\r\n");
			success = false;
		}

		if (success) {
			std::string username = msclr::interop::marshal_as<std::string>(instagramUsernameTextBox->Text);
			std::string password =  msclr::interop::marshal_as<std::string>(instagramUsernamePasswordTextBox->Text);
			std::string profiles = msclr::interop::marshal_as<std::string>(instagramProfilesTextBox->Text);
			double postCap = System::Convert::ToDouble(instagramProfilePostCountTextBox->Text);
			std::string exportFolderPath = msclr::interop::marshal_as<std::string>(instagramExportFolderPathValueLabel->Text);
			using ICT1009::WebScrapping::InstagramScrapper;
			typedef std::shared_ptr<InstagramScrapper> InstagramScrapperPtr;
			InstagramScrapperPtr scrapper(new InstagramScrapper);
			instagramConsole->AppendText("*Executing profile scraping procedure...\r\n");
			try {
				if (scrapper->scrapeByProfiles(username, password, profiles, postCap, exportFolderPath) == 1)
					instagramConsole->AppendText("*Finished profiles scrapping procedure. \r\n");
			} catch (...) {
				instagramConsole->AppendText("*Error occured during profiles scraping procedure...\r\n");
			}
		}
	}
	private: System::Void displayJsonSelectJsonButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displayJsonLoadFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			displayJsonFilePathValueLabel->Text = displayJsonLoadFileDialog->FileName;
			using json = nlohmann::json;

			try {
				std::string fileName = msclr::interop::marshal_as<std::string>(displayJsonLoadFileDialog->FileName);
				std::ifstream i(fileName);
				json j; i >> j; i.close();
				std::stringstream displayOutput;
				displayOutput << std::setw(4) << j << std::endl;
				displayJsonFileOutputRichTextBox->Text = gcnew System::String(displayOutput.str().c_str());
			} catch (...) {

			}
			

		}
	}
	private: System::Void displayJsonSaveAsButton_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (displayJsonFileOutputRichTextBox->Text != "") {
			if (displayJsonSaveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				std::string output = msclr::interop::marshal_as<std::string>(displayJsonFileOutputRichTextBox->Text);
				std::string savePath = msclr::interop::marshal_as<std::string>(displayJsonSaveFileDialog->FileName);
				if (FileUtility::saveStringToFile(output, savePath))
					MessageBox::Show(gcnew System::String(("Successfully saved to file"+savePath).c_str()));
			}
		} else {
			MessageBox::Show("There is no data in the textbox.");
		}
	}

	private: System::Void imageOcrBrowseJsonButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (imageOcrLoadFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			imageOcrFilePathValueLabel->Text = imageOcrLoadFileDialog->FileName;
		}
	}




	private: System::Void imageOcrExecuteButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (imageOcrFilePathValueLabel->Text == "None" or imageOcrFilePathValueLabel->Text == "") {
			imageOcrConsoleTextBox->AppendText("Please choose json file to conduct OCR on \r\n");
		} else {
			using nlohmann::json;
			std::string filePath = msclr::interop::marshal_as<std::string>(imageOcrFilePathValueLabel->Text);
			typedef std::shared_ptr<ICT1009::TextRecognition::OCRUtility> OCRPtr;
			OCRPtr extractor(new ICT1009::TextRecognition::OCRUtility);
			imageOcrConsoleTextBox->AppendText("Executing OCR procedure...\r\n");
			
			int returnCode = extractor->appendImagesTextToJson(filePath);
			switch (returnCode) {
				case -1:
					imageOcrConsoleTextBox->AppendText("Unable to read specified Json file\r\n");
					break;
				case -2:
					imageOcrConsoleTextBox->AppendText("Unable to append to Json file\r\n");
					break;
				default:
					if (returnCode > 1) {

						imageOcrConsoleTextBox->AppendText("Successfully appended image text to file\r\n");
					}
					//imageOcrConsoleTextBox->AppendText("Default Case\r\n");
			}
		}
	}


}; //Endpoint
}
