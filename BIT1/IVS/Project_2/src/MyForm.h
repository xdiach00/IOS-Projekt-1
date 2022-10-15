#pragma once

#include "MathLibrary.h"
#include "MathLibraryP.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <iostream>
#include <string>
#include <string>

using namespace MathLibrary;
using namespace MathLibraryP;

namespace Calculat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonC;
	private: System::Windows::Forms::Button^ buttonBack;
	private: System::Windows::Forms::Button^ buttonPerc;
	private: System::Windows::Forms::Button^ buttonLog;

	private: System::Windows::Forms::Button^ buttonDiv;
	private: System::Windows::Forms::Button^ buttonSq;
	private: System::Windows::Forms::Button^ buttonPow;
	private: System::Windows::Forms::Button^ buttonFac;
	private: System::Windows::Forms::Button^ buttonTim;
	private: System::Windows::Forms::Button^ buttonNine;
	private: System::Windows::Forms::Button^ buttonEight;
	private: System::Windows::Forms::Button^ buttonSeven;
	private: System::Windows::Forms::Button^ buttonMinus;
	private: System::Windows::Forms::Button^ buttonSix;
	private: System::Windows::Forms::Button^ buttonFive;
	private: System::Windows::Forms::Button^ buttonFour;
	private: System::Windows::Forms::Button^ buttonPlus;
	private: System::Windows::Forms::Button^ buttonThree;
	private: System::Windows::Forms::Button^ buttonTwo;
	private: System::Windows::Forms::Button^ buttonOne;
	private: System::Windows::Forms::Button^ buttonEquals;
	private: System::Windows::Forms::Button^ buttonDot;
	private: System::Windows::Forms::Button^ buttonZero;

	private: System::Windows::Forms::Label^ labelDisplay;


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->buttonC = (gcnew System::Windows::Forms::Button());
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->buttonPerc = (gcnew System::Windows::Forms::Button());
			this->buttonLog = (gcnew System::Windows::Forms::Button());
			this->buttonDiv = (gcnew System::Windows::Forms::Button());
			this->buttonSq = (gcnew System::Windows::Forms::Button());
			this->buttonPow = (gcnew System::Windows::Forms::Button());
			this->buttonFac = (gcnew System::Windows::Forms::Button());
			this->buttonTim = (gcnew System::Windows::Forms::Button());
			this->buttonNine = (gcnew System::Windows::Forms::Button());
			this->buttonEight = (gcnew System::Windows::Forms::Button());
			this->buttonSeven = (gcnew System::Windows::Forms::Button());
			this->buttonMinus = (gcnew System::Windows::Forms::Button());
			this->buttonSix = (gcnew System::Windows::Forms::Button());
			this->buttonFive = (gcnew System::Windows::Forms::Button());
			this->buttonFour = (gcnew System::Windows::Forms::Button());
			this->buttonPlus = (gcnew System::Windows::Forms::Button());
			this->buttonThree = (gcnew System::Windows::Forms::Button());
			this->buttonTwo = (gcnew System::Windows::Forms::Button());
			this->buttonOne = (gcnew System::Windows::Forms::Button());
			this->buttonEquals = (gcnew System::Windows::Forms::Button());
			this->buttonDot = (gcnew System::Windows::Forms::Button());
			this->buttonZero = (gcnew System::Windows::Forms::Button());
			this->labelDisplay = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			//
			// Colors inicialization
			//
			Color btnGrayColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(196)));
			Color btnOrangeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(153)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));

			// 
			// buttonC
			// 
			this->buttonC->BackColor = btnOrangeColor;
			this->buttonC->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonC->Location = System::Drawing::Point(5, 90);
			this->buttonC->Margin = System::Windows::Forms::Padding(4);
			this->buttonC->Name = L"buttonC";
			this->buttonC->Size = System::Drawing::Size(107, 98);
			this->buttonC->TabIndex = 23;
            this->TabStop = false;
			this->buttonC->Text = L"C";
			this->buttonC->UseVisualStyleBackColor = false;
			this->buttonC->Click += gcnew System::EventHandler(this, &MyForm::CleanLabel);
			// 
			// buttonBack
			// 
			this->buttonBack->BackColor = btnOrangeColor;
			this->buttonBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonBack->Location = System::Drawing::Point(120, 90);
			this->buttonBack->Margin = System::Windows::Forms::Padding(4);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(107, 98);
			this->buttonBack->TabIndex = 2;
            this->TabStop = false;
			this->buttonBack->Text = L"🡰";
			this->buttonBack->UseVisualStyleBackColor = false;
			this->buttonBack->Click += gcnew System::EventHandler(this, &MyForm::ClickOnDel);
			// 
			// buttonPerc
			// 
			this->buttonPerc->BackColor = btnOrangeColor;
			this->buttonPerc->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPerc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonPerc->Location = System::Drawing::Point(235, 90);
			this->buttonPerc->Margin = System::Windows::Forms::Padding(4);
			this->buttonPerc->Name = L"buttonPerc";
			this->buttonPerc->Size = System::Drawing::Size(107, 98);
			this->buttonPerc->TabIndex = 3;
            this->TabStop = false;
			this->buttonPerc->Text = L"%";
			this->buttonPerc->UseVisualStyleBackColor = false;
			this->buttonPerc->Click += gcnew System::EventHandler(this, &MyForm::OneParamOperators);
			// 
			// buttonLog
			// 
			this->buttonLog->BackColor = btnOrangeColor;
			this->buttonLog->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonLog->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 23.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonLog->Location = System::Drawing::Point(349, 90);
			this->buttonLog->Margin = System::Windows::Forms::Padding(4);
			this->buttonLog->Name = L"buttonLog";
			this->buttonLog->Size = System::Drawing::Size(107, 98);
			this->buttonLog->TabIndex = 4;
            this->TabStop = false;
			this->buttonLog->Text = L"Log";
			this->buttonLog->UseVisualStyleBackColor = false;
			this->buttonLog->Click += gcnew System::EventHandler(this, &MyForm::OneParamOperators);
			// 
			// buttonDiv
			// 
			this->buttonDiv->BackColor = btnOrangeColor;
			this->buttonDiv->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDiv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonDiv->Location = System::Drawing::Point(349, 196);
			this->buttonDiv->Margin = System::Windows::Forms::Padding(4);
			this->buttonDiv->Name = L"buttonDiv";
			this->buttonDiv->Size = System::Drawing::Size(107, 98);
			this->buttonDiv->TabIndex = 8;
            this->TabStop = false;
			this->buttonDiv->Text = L"/";
			this->buttonDiv->UseVisualStyleBackColor = false;
			this->buttonDiv->Click += gcnew System::EventHandler(this, &MyForm::MainArithmeticOperator);
			// 
			// buttonSq
			// 
			this->buttonSq->BackColor = btnOrangeColor;
			this->buttonSq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSq->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonSq->Location = System::Drawing::Point(235, 196);
			this->buttonSq->Margin = System::Windows::Forms::Padding(4);
			this->buttonSq->Name = L"buttonSq";
			this->buttonSq->Size = System::Drawing::Size(107, 98);
			this->buttonSq->TabIndex = 7;
            this->TabStop = false;
			this->buttonSq->Text = L"√";
			this->buttonSq->UseVisualStyleBackColor = false;
			this->buttonSq->Click += gcnew System::EventHandler(this, &MyForm::MainArithmeticOperator);
			// 
			// buttonPow
			// 
			this->buttonPow->BackColor = btnOrangeColor;
			this->buttonPow->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonPow->Location = System::Drawing::Point(120, 196);
			this->buttonPow->Margin = System::Windows::Forms::Padding(4);
			this->buttonPow->Name = L"buttonPow";
			this->buttonPow->Size = System::Drawing::Size(107, 98);
			this->buttonPow->TabIndex = 6;
            this->TabStop = false;
			this->buttonPow->Text = L"xʸ";
			this->buttonPow->UseVisualStyleBackColor = false;
			this->buttonPow->Click += gcnew System::EventHandler(this, &MyForm::MainArithmeticOperator);
			// 
			// buttonFac
			// 
			this->buttonFac->BackColor = btnOrangeColor;
			this->buttonFac->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonFac->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonFac->Location = System::Drawing::Point(5, 196);
			this->buttonFac->Margin = System::Windows::Forms::Padding(4);
			this->buttonFac->Name = L"buttonFac";
			this->buttonFac->Size = System::Drawing::Size(107, 98);
			this->buttonFac->TabIndex = 5;
            this->TabStop = false;
			this->buttonFac->Text = L"!";
			this->buttonFac->UseVisualStyleBackColor = false;
			this->buttonFac->Click += gcnew System::EventHandler(this, &MyForm::OneParamOperators);
			// 
			// buttonTim
			// 
			this->buttonTim->BackColor = btnOrangeColor;
			this->buttonTim->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonTim->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonTim->Location = System::Drawing::Point(349, 302);
			this->buttonTim->Margin = System::Windows::Forms::Padding(4);
			this->buttonTim->Name = L"buttonTim";
            this->TabStop = false;
			this->buttonTim->Size = System::Drawing::Size(107, 98);
			this->buttonTim->TabIndex = 12;
			this->buttonTim->Text = L"x";
			this->buttonTim->UseVisualStyleBackColor = false;
			this->buttonTim->Click += gcnew System::EventHandler(this, &MyForm::MainArithmeticOperator);
			// 
			// buttonNine
			// 
			this->buttonNine->BackColor = btnGrayColor;
			this->buttonNine->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonNine->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonNine->Location = System::Drawing::Point(235, 302);
			this->buttonNine->Margin = System::Windows::Forms::Padding(4);
			this->buttonNine->Name = L"buttonNine";
            this->TabStop = false;
			this->buttonNine->Size = System::Drawing::Size(107, 98);
			this->buttonNine->TabIndex = 11;
			this->buttonNine->Text = L"9";
			this->buttonNine->UseVisualStyleBackColor = false;
			this->buttonNine->Click += gcnew System::EventHandler(this, &MyForm::buttonNum_Click);
			// 
			// buttonEight
			// 
			this->buttonEight->BackColor = btnGrayColor;
			this->buttonEight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonEight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonEight->Location = System::Drawing::Point(120, 302);
			this->buttonEight->Margin = System::Windows::Forms::Padding(4);
			this->buttonEight->Name = L"buttonEight";
            this->TabStop = false;
			this->buttonEight->Size = System::Drawing::Size(107, 98);
			this->buttonEight->TabIndex = 10;
			this->buttonEight->Text = L"8";
			this->buttonEight->UseVisualStyleBackColor = false;
			this->buttonEight->Click += gcnew System::EventHandler(this, &MyForm::buttonNum_Click);
			// 
			// buttonSeven
			// 
			this->buttonSeven->BackColor = btnGrayColor;
			this->buttonSeven->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSeven->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonSeven->Location = System::Drawing::Point(5, 302);
			this->buttonSeven->Margin = System::Windows::Forms::Padding(4);
			this->buttonSeven->Name = L"buttonSeven";
            this->TabStop = false;
			this->buttonSeven->Size = System::Drawing::Size(107, 98);
			this->buttonSeven->TabIndex = 9;
			this->buttonSeven->Text = L"7";
			this->buttonSeven->UseVisualStyleBackColor = false;
			this->buttonSeven->Click += gcnew System::EventHandler(this, &MyForm::buttonNum_Click);
			// 
			// buttonMinus
			// 
			this->buttonMinus->BackColor = btnOrangeColor;
			this->buttonMinus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMinus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonMinus->Location = System::Drawing::Point(349, 407);
			this->buttonMinus->Margin = System::Windows::Forms::Padding(4);
			this->buttonMinus->Name = L"buttonMinus";
            this->TabStop = false;
			this->buttonMinus->Size = System::Drawing::Size(107, 98);
			this->buttonMinus->TabIndex = 16;
			this->buttonMinus->Text = L"-";
			this->buttonMinus->UseVisualStyleBackColor = false;
			this->buttonMinus->Click += gcnew System::EventHandler(this, &MyForm::MainArithmeticOperator);
			// 
			// buttonSix
			// 
			this->buttonSix->BackColor = btnGrayColor;
			this->buttonSix->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonSix->Location = System::Drawing::Point(235, 407);
			this->buttonSix->Margin = System::Windows::Forms::Padding(0);
			this->buttonSix->Name = L"buttonSix";
			this->buttonSix->Size = System::Drawing::Size(107, 98);
			this->buttonSix->TabIndex = 15;
            this->TabStop = false;
			this->buttonSix->Text = L"6";
			this->buttonSix->UseVisualStyleBackColor = false;
			this->buttonSix->Click += gcnew System::EventHandler(this, &MyForm::buttonNum_Click);
			// 
			// buttonFive
			// 
			this->buttonFive->BackColor = btnGrayColor;
			this->buttonFive->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonFive->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonFive->Location = System::Drawing::Point(120, 407);
			this->buttonFive->Margin = System::Windows::Forms::Padding(4);
			this->buttonFive->Name = L"buttonFive";
			this->buttonFive->Size = System::Drawing::Size(107, 98);
			this->buttonFive->TabIndex = 14;
            this->TabStop = false;
			this->buttonFive->Text = L"5";
			this->buttonFive->UseVisualStyleBackColor = false;
			this->buttonFive->Click += gcnew System::EventHandler(this, &MyForm::buttonNum_Click);
			// 
			// buttonFour
			// 
			this->buttonFour->BackColor = btnGrayColor;
			this->buttonFour->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonFour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonFour->Location = System::Drawing::Point(5, 407);
			this->buttonFour->Margin = System::Windows::Forms::Padding(4);
			this->buttonFour->Name = L"buttonFour";
            this->TabStop = false;
			this->buttonFour->Size = System::Drawing::Size(107, 98);
			this->buttonFour->TabIndex = 13;
			this->buttonFour->Text = L"4";
			this->buttonFour->UseVisualStyleBackColor = false;
			this->buttonFour->Click += gcnew System::EventHandler(this, &MyForm::buttonNum_Click);
			// 
			// buttonPlus
			// 
			this->buttonPlus->BackColor = btnOrangeColor;
			this->buttonPlus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPlus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonPlus->Location = System::Drawing::Point(349, 513);
			this->buttonPlus->Margin = System::Windows::Forms::Padding(4);
			this->buttonPlus->Name = L"buttonPlus";
            this->TabStop = false;
			this->buttonPlus->Size = System::Drawing::Size(107, 98);
			this->buttonPlus->TabIndex = 20;
			this->buttonPlus->Text = L"+";
			this->buttonPlus->UseVisualStyleBackColor = false;
			this->buttonPlus->Click += gcnew System::EventHandler(this, &MyForm::MainArithmeticOperator);
			// 
			// buttonThree
			// 
			this->buttonThree->BackColor = btnGrayColor;
			this->buttonThree->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonThree->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonThree->Location = System::Drawing::Point(235, 513);
			this->buttonThree->Margin = System::Windows::Forms::Padding(4);
			this->buttonThree->Name = L"buttonThree";
			this->buttonThree->Size = System::Drawing::Size(107, 98);
			this->buttonThree->TabIndex = 19;
            this->TabStop = false;
			this->buttonThree->Text = L"3";
			this->buttonThree->UseVisualStyleBackColor = false;
			this->buttonThree->Click += gcnew System::EventHandler(this, &MyForm::buttonNum_Click);
			// 
			// buttonTwo
			// 
			this->buttonTwo->BackColor = btnGrayColor;
			this->buttonTwo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonTwo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonTwo->Location = System::Drawing::Point(120, 513);
			this->buttonTwo->Margin = System::Windows::Forms::Padding(4);
			this->buttonTwo->Name = L"buttonTwo";
			this->buttonTwo->Size = System::Drawing::Size(107, 98);
			this->buttonTwo->TabIndex = 18;
            this->TabStop = false;
			this->buttonTwo->Text = L"2";
			this->buttonTwo->UseVisualStyleBackColor = false;
			this->buttonTwo->Click += gcnew System::EventHandler(this, &MyForm::buttonNum_Click);
			// 
			// buttonOne
			// 
			this->buttonOne->BackColor = btnGrayColor;
			this->buttonOne->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonOne->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonOne->Location = System::Drawing::Point(5, 513);
			this->buttonOne->Margin = System::Windows::Forms::Padding(4);
			this->buttonOne->Name = L"buttonOne";
			this->buttonOne->Size = System::Drawing::Size(107, 98);
			this->buttonOne->TabIndex = 17;
            this->TabStop = false;
			this->buttonOne->Text = L"1";
			this->buttonOne->UseVisualStyleBackColor = false;
			this->buttonOne->Click += gcnew System::EventHandler(this, &MyForm::buttonNum_Click);
			// 
			// buttonEquals
			// 
			this->buttonEquals->BackColor = btnOrangeColor;
			this->buttonEquals->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonEquals->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonEquals->Location = System::Drawing::Point(235, 619);
			this->buttonEquals->Margin = System::Windows::Forms::Padding(4);
			this->buttonEquals->Name = L"buttonEquals";
			this->buttonEquals->Size = System::Drawing::Size(221, 98);
			this->buttonEquals->TabIndex = 1;
			this->buttonEquals->Text = L"=";
			this->buttonEquals->UseVisualStyleBackColor = false;
			this->buttonEquals->Click += gcnew System::EventHandler(this, &MyForm::ClickOnEquals);
			// 
			// buttonDot
			// 
			this->buttonDot->BackColor = btnGrayColor;
			this->buttonDot->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonDot->Location = System::Drawing::Point(120, 619);
			this->buttonDot->Margin = System::Windows::Forms::Padding(4);
			this->buttonDot->Name = L"buttonDot";
			this->buttonDot->Size = System::Drawing::Size(107, 98);
			this->buttonDot->TabIndex = 22;
            this->TabStop = false;
			this->buttonDot->Text = L".";
			this->buttonDot->UseVisualStyleBackColor = false;
			this->buttonDot->Click += gcnew System::EventHandler(this, &MyForm::ClickOnDot);
			// 
			// buttonZero
			// 
			this->buttonZero->BackColor = btnGrayColor;
			this->buttonZero->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonZero->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonZero->Location = System::Drawing::Point(5, 619);
			this->buttonZero->Margin = System::Windows::Forms::Padding(4);
			this->buttonZero->Name = L"buttonZero";
			this->buttonZero->Size = System::Drawing::Size(107, 98);
			this->buttonZero->TabIndex = 21;
			this->buttonZero->Text = L"0";
            this->TabStop = false;
			this->buttonZero->UseVisualStyleBackColor = false;
			this->buttonZero->Click += gcnew System::EventHandler(this, &MyForm::buttonNum_Click);
			// 
			// labelDisplay
			// 
			this->labelDisplay->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelDisplay->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->labelDisplay->Location = System::Drawing::Point(5, 11);
			this->labelDisplay->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelDisplay->Name = L"labelDisplay";
			this->labelDisplay->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->labelDisplay->Size = System::Drawing::Size(459, 75);
			this->labelDisplay->TabIndex = 24;
			this->labelDisplay->Text = L"0";
			this->labelDisplay->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->labelDisplay->TextChanged += gcnew System::EventHandler(this, &MyForm::labelDisplay_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(459, 720);
			this->Controls->Add(this->labelDisplay);
			this->Controls->Add(this->buttonEquals);
			this->Controls->Add(this->buttonDot);
			this->Controls->Add(this->buttonZero);
			this->Controls->Add(this->buttonPlus);
			this->Controls->Add(this->buttonThree);
			this->Controls->Add(this->buttonTwo);
			this->Controls->Add(this->buttonOne);
			this->Controls->Add(this->buttonMinus);
			this->Controls->Add(this->buttonSix);
			this->Controls->Add(this->buttonFive);
			this->Controls->Add(this->buttonFour);
			this->Controls->Add(this->buttonTim);
			this->Controls->Add(this->buttonNine);
			this->Controls->Add(this->buttonEight);
			this->Controls->Add(this->buttonSeven);
			this->Controls->Add(this->buttonDiv);
			this->Controls->Add(this->buttonSq);
			this->Controls->Add(this->buttonPow);
			this->Controls->Add(this->buttonFac);
			this->Controls->Add(this->buttonLog);
			this->Controls->Add(this->buttonPerc);
			this->Controls->Add(this->buttonBack);
			this->Controls->Add(this->buttonC);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = true;
			this->Text = L"Calculator";
			this->Icon = gcnew System::Drawing::Icon(L"app.ico");
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::KeyboardInic);
			this->ResumeLayout(false);

		}
		//
		// Variables for libraries implementation
		//
		double firstNum, secondNum, ansNum;
		int symbolOperator;

#pragma endregion
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

}
//
// Function for printing numbers from buttons
//
private: System::Void buttonNum_Click(System::Object^ sender, System::EventArgs^ e) {

	Button^ num = safe_cast<Button^>(sender);

	if (labelDisplay->Text == "0") {
		labelDisplay->Text = num->Text;
	}
	else
	{
		labelDisplay->Text = labelDisplay->Text + num->Text;
	}
}
//
// Function for working with Math Operators with 2 params. Minus button can be used for changing sign of number
//
private: System::Void MainArithmeticOperator(System::Object^ sender, System::EventArgs^ e) {

	Button^ MAop = safe_cast<Button^>(sender);

	if (MAop->TabIndex == 16 && labelDisplay->Text == "0") {
		labelDisplay->Text = "-";
	}
	else {
		firstNum = Double::Parse(labelDisplay->Text);
		labelDisplay->Text = "";
		symbolOperator = MAop->TabIndex;
	}


}
//
// Function for removing all numbers
//
private: System::Void CleanLabel(System::Object^ sender, System::EventArgs^ e) {

	labelDisplay->Text = "0";
    firstNum = NULL;
    secondNum = NULL;
    ansNum = NULL;
    symbolOperator = NULL;
}
//
// Function for printing ','
//
private: System::Void ClickOnDot(System::Object^ sender, System::EventArgs^ e) {

	if (!labelDisplay->Text->Contains(",")) {
		labelDisplay->Text = labelDisplay->Text + ",";
	}
}
//
// Function for removing last number
//
private: System::Void ClickOnDel(System::Object^ sender, System::EventArgs^ e) {

	if (labelDisplay->Text->Length > 0) {
		labelDisplay->Text = labelDisplay->Text->Remove(labelDisplay->Text->Length - 1, 1);
	}
}
//
// Function for showing 0 if label is empty
//
private: System::Void labelDisplay_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if (labelDisplay->Text == "") {
		labelDisplay->Text = "0";
	}
}
//
// Function for working with EQUALS button
//
private: System::Void ClickOnEquals(System::Object^ sender, System::EventArgs^ e) {

	secondNum = Double::Parse(labelDisplay->Text);

	switch (symbolOperator) {
		case 20:
			ansNum = Arithmetic::Add(firstNum, secondNum);
			labelDisplay->Text = System::Convert::ToString(ansNum);
			break;
		case 8:
			try
			{
				ansNum = Arithmetic::Divide(firstNum, secondNum);
				labelDisplay->Text = System::Convert::ToString(ansNum);
			}
			catch (const std::invalid_argument & err)
			{
				MessageBox::Show(gcnew String(err.what()), "Error!");
			}
			break;

		case 12:
			ansNum = Arithmetic::Multiply(firstNum, secondNum);
			labelDisplay->Text = System::Convert::ToString(ansNum);
			break;

		case 16:
			ansNum = Arithmetic::Subtract(firstNum, secondNum);
			labelDisplay->Text = System::Convert::ToString(ansNum);
			break;

		case 7:
			try
			{
				ansNum = Operations::Sqrt(firstNum, secondNum);
				labelDisplay->Text = System::Convert::ToString(ansNum);
			}
			catch (const std::invalid_argument& err)
			{
				MessageBox::Show(gcnew String(err.what()), "Error!");
			}
			break;
		case 6:
			try
			{
				ansNum = Operations::Involution(firstNum, secondNum);
				labelDisplay->Text = System::Convert::ToString(ansNum);
			}
			catch (const std::invalid_argument& err)
			{
				MessageBox::Show(gcnew String(err.what()), "Error!");
			}
			break;
	}
    firstNum = NULL;
    secondNum = NULL;
    ansNum = NULL;
    symbolOperator = NULL;

}
//
// Function for working with Math Operators with 1 param
//
private: System::Void OneParamOperators(System::Object^ sender, System::EventArgs^ e) {

	Button^ MAop = safe_cast<Button^>(sender);
	symbolOperator = MAop->TabIndex;
	firstNum = Double::Parse(labelDisplay->Text);

	switch (symbolOperator) {
	case 3:
		ansNum = Operations::Percentage(firstNum);
		labelDisplay->Text = System::Convert::ToString(ansNum);
		break;
	case 4:
		try
		{
			ansNum = Operations::Logarithm(firstNum);
			labelDisplay->Text = System::Convert::ToString(ansNum);
		}
		catch (const std::invalid_argument& err)
		{
			MessageBox::Show(gcnew String(err.what()), "Error!");
		}
		break;

	case 5:
		try
		{
			ansNum = Operations::Factorial(firstNum);
			labelDisplay->Text = System::Convert::ToString(ansNum);
		}
		catch (const std::invalid_argument& err)
		{
			MessageBox::Show(gcnew String(err.what()), "Error!");
		}
		break;
	}

}
//
// Keyboard implementation
//
private: System::Void KeyboardInic(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	int num;

    buttonEquals->Focus();

    if (e->KeyCode == Keys::NumPad0 || e->KeyCode == Keys::D0)
		num = 0;
	else if (e->KeyCode == Keys::NumPad1 || e->KeyCode == Keys::D1)
		num = 1;
	else if (e->KeyCode == Keys::NumPad2 || e->KeyCode == Keys::D2)
		num = 2;
	else if (e->KeyCode == Keys::NumPad3 || e->KeyCode == Keys::D3)
		num = 3;
	else if (e->KeyCode == Keys::NumPad4 || e->KeyCode == Keys::D4)
		num = 4;
	else if (e->KeyCode == Keys::NumPad5 || e->KeyCode == Keys::D5)
		num = 5;
	else if (e->KeyCode == Keys::NumPad6 || e->KeyCode == Keys::D6)
		num = 6;
	else if (e->KeyCode == Keys::NumPad7 || e->KeyCode == Keys::D7)
		num = 7;
	else if (e->KeyCode == Keys::NumPad8 || e->KeyCode == Keys::D8)
		num = 8;
	else if (e->KeyCode == Keys::NumPad9 || e->KeyCode == Keys::D9)
		num = 9;
	else if (e->KeyCode == Keys::Decimal || e->KeyCode == Keys::OemPeriod) {
		if (!labelDisplay->Text->Contains(",")) {
			labelDisplay->Text = labelDisplay->Text + ",";
		}
		return;
	}
	else if (e->KeyCode == Keys::Subtract) {
		MainArithmeticOperator(buttonMinus, e);
		return;
	}
	else if (e->KeyCode == Keys::Add) {
		MainArithmeticOperator(buttonPlus, e);
		return;
	}
	else if (e->KeyCode == Keys::Divide) {
		MainArithmeticOperator(buttonDiv, e);
		return;
	}
	else if (e->KeyCode == Keys::Multiply) {
		MainArithmeticOperator(buttonTim, e);
		return;
	}
   // else if (e->KeyCode == Keys::Enter) {
    //    labelDisplay->Text = symbolOperator.ToString();
    //    return;
    //}
	else 
		return;
		
	if (num >= 0 && num <= 9) {
		if (labelDisplay->Text == "0") {
			labelDisplay->Text = num.ToString();
		}
		else
		{
			labelDisplay->Text = labelDisplay->Text + num.ToString();
		}
	}
	return;
}
};
}