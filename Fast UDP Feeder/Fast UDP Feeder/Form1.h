#pragma once

#include "stdafx.h"

#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#pragma comment (lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <windows.h>
#include <string>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

//Global Vars like you shouldn't do
WSADATA wsaData;
SOCKET sd;							/* Socket descriptor of server */
int iResult;
SOCKADDR_IN addr;

typedef unsigned short USHORT;

unsigned short X;
unsigned short Y;
unsigned short Z;
unsigned short RX;
unsigned short ZR;
unsigned short BUT1;
unsigned short BUT2;
unsigned short Reset;

char buf[16]={0};
char xbuf[2048]={0};

//Network Configuration
//Standard IP Address is local IP
std::string ip ="127.0.0.1";
//TestIP
//std::string ip ="192.168.92.196";
const char* ip_s = ip.c_str();
unsigned short port = 2015;



namespace FastUDPFeeder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//tbIP-> Text = ip;
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  XValue;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::TextBox^  YValue;
	private: System::Windows::Forms::TextBox^  ZValue;
	private: System::Windows::Forms::TextBox^  RXValue;
	private: System::Windows::Forms::TextBox^  ZRValue;

	private: System::Windows::Forms::TextBox^  BUT1Value;
	private: System::Windows::Forms::TextBox^  BUT2Value;
	private: System::Windows::Forms::TextBox^  ResetValue;







	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;

	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::TextBox^  tbIP;


	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  tbPort;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::TextBox^  textstring;

	private: System::Windows::Forms::Button^  button13;



	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->XValue = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->YValue = (gcnew System::Windows::Forms::TextBox());
			this->ZValue = (gcnew System::Windows::Forms::TextBox());
			this->RXValue = (gcnew System::Windows::Forms::TextBox());
			this->ZRValue = (gcnew System::Windows::Forms::TextBox());
			this->BUT1Value = (gcnew System::Windows::Forms::TextBox());
			this->BUT2Value = (gcnew System::Windows::Forms::TextBox());
			this->ResetValue = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->tbIP = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tbPort = (gcnew System::Windows::Forms::TextBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->textstring = (gcnew System::Windows::Forms::TextBox());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 102);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(266, 42);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Feeder Setup";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(12, 76);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(266, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// XValue
			// 
			this->XValue->Location = System::Drawing::Point(56, 150);
			this->XValue->Name = L"XValue";
			this->XValue->Size = System::Drawing::Size(100, 20);
			this->XValue->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 150);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"X-Axis";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 179);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Y-Axis";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 208);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Z-Axis";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 237);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"RX-Axis";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(159, 150);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(119, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Get X Value";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(159, 382);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(119, 58);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Send";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(159, 179);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(119, 23);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Get Y Value";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(159, 208);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(119, 23);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Get Z Value";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(159, 237);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(119, 23);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Get RX Value";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(159, 266);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(119, 23);
			this->button7->TabIndex = 12;
			this->button7->Text = L"Get ZR Value";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(159, 295);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(119, 23);
			this->button8->TabIndex = 13;
			this->button8->Text = L"Get BUT1 Value";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(159, 324);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(119, 23);
			this->button9->TabIndex = 14;
			this->button9->Text = L"Get BUT2 Value";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(159, 353);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(119, 23);
			this->button10->TabIndex = 15;
			this->button10->Text = L"Reset";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// YValue
			// 
			this->YValue->Location = System::Drawing::Point(56, 179);
			this->YValue->Name = L"YValue";
			this->YValue->Size = System::Drawing::Size(100, 20);
			this->YValue->TabIndex = 16;
			// 
			// ZValue
			// 
			this->ZValue->Location = System::Drawing::Point(56, 208);
			this->ZValue->Name = L"ZValue";
			this->ZValue->Size = System::Drawing::Size(100, 20);
			this->ZValue->TabIndex = 17;
			// 
			// RXValue
			// 
			this->RXValue->Location = System::Drawing::Point(56, 237);
			this->RXValue->Name = L"RXValue";
			this->RXValue->Size = System::Drawing::Size(100, 20);
			this->RXValue->TabIndex = 18;
			// 
			// ZRValue
			// 
			this->ZRValue->Location = System::Drawing::Point(56, 266);
			this->ZRValue->Name = L"ZRValue";
			this->ZRValue->Size = System::Drawing::Size(100, 20);
			this->ZRValue->TabIndex = 19;
			// 
			// BUT1Value
			// 
			this->BUT1Value->Location = System::Drawing::Point(56, 295);
			this->BUT1Value->Name = L"BUT1Value";
			this->BUT1Value->Size = System::Drawing::Size(100, 20);
			this->BUT1Value->TabIndex = 20;
			// 
			// BUT2Value
			// 
			this->BUT2Value->Location = System::Drawing::Point(56, 324);
			this->BUT2Value->Name = L"BUT2Value";
			this->BUT2Value->Size = System::Drawing::Size(100, 20);
			this->BUT2Value->TabIndex = 21;
			// 
			// ResetValue
			// 
			this->ResetValue->Location = System::Drawing::Point(56, 353);
			this->ResetValue->Name = L"ResetValue";
			this->ResetValue->Size = System::Drawing::Size(100, 20);
			this->ResetValue->TabIndex = 22;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 266);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"ZR-Axis";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(9, 295);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 24;
			this->label6->Text = L"BUT1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(9, 324);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 25;
			this->label7->Text = L"BUT2";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(9, 353);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 26;
			this->label8->Text = L"Reset";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(12, 47);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(266, 23);
			this->button11->TabIndex = 28;
			this->button11->Text = L"Get Network Preferences";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// tbIP
			// 
			this->tbIP->Location = System::Drawing::Point(56, 24);
			this->tbIP->Name = L"tbIP";
			this->tbIP->Size = System::Drawing::Size(100, 20);
			this->tbIP->TabIndex = 29;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 24);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(43, 13);
			this->label9->TabIndex = 30;
			this->label9->Text = L"TCP/IP";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(165, 24);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(37, 13);
			this->label10->TabIndex = 31;
			this->label10->Text = L"PORT";
			// 
			// tbPort
			// 
			this->tbPort->Location = System::Drawing::Point(208, 24);
			this->tbPort->Name = L"tbPort";
			this->tbPort->Size = System::Drawing::Size(70, 20);
			this->tbPort->TabIndex = 32;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(12, 382);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(141, 58);
			this->button12->TabIndex = 33;
			this->button12->Text = L"Fast Send";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// textstring
			// 
			this->textstring->Location = System::Drawing::Point(327, 24);
			this->textstring->Multiline = true;
			this->textstring->Name = L"textstring";
			this->textstring->Size = System::Drawing::Size(563, 120);
			this->textstring->TabIndex = 34;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(741, 149);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(149, 50);
			this->button13->TabIndex = 35;
			this->button13->Text = L"Send String";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(902, 492);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->textstring);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->tbPort);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->tbIP);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->ResetValue);
			this->Controls->Add(this->BUT2Value);
			this->Controls->Add(this->BUT1Value);
			this->Controls->Add(this->ZRValue);
			this->Controls->Add(this->RXValue);
			this->Controls->Add(this->ZValue);
			this->Controls->Add(this->YValue);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->XValue);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				textBox1->Text = "";
				WORD DllVersion = MAKEWORD(2,2);
				// Initialize Winsock
				int startup_RetVal = WSAStartup(DllVersion, &wsaData);
   
				sd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

				if (sd == INVALID_SOCKET)
				{
					textBox1->Text = "Could not create socket";
					WSACleanup();
				}
				else textBox1->Text = "New socket successfully created";

			//Home test mode 
			//addr.sin_addr.s_addr = inet_addr("192.168.92.187");
			addr.sin_addr.s_addr = inet_addr(ip_s);
			addr.sin_family = AF_INET;
			addr.sin_port = htons(port);

			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 	//TestMessage
				//char buf1[16] = "This is a message"; 
				String^ test = gcnew String( buf, 0, 16);


				int send_RetVal = sendto(sd, buf, 16, NULL, (SOCKADDR*)&addr, sizeof(addr));

				if (send_RetVal == SOCKET_ERROR)
				{
				printf("An error occured while send operation ");
				getchar();
				}

				
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			   X = Convert::ToInt32(XValue->Text);
			   *((USHORT*)buf) = X;
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 Y = Convert::ToInt32(YValue->Text);
			  *((USHORT*)buf+1) = Y;
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 Z = Convert::ToInt32(ZValue->Text);
			  *((USHORT*)buf+2) = Z;
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 RX = Convert::ToInt32(RXValue->Text);
			 *((USHORT*)buf+3) = RX;
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			  ZR = Convert::ToInt32(ZRValue->Text);
			  *((USHORT*)buf+4) = ZR;
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			  BUT1 = Convert::ToInt32(BUT1Value->Text);
			  *((USHORT*)buf+5) = BUT1;
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			  BUT2 = Convert::ToInt32(BUT2Value->Text);
			  *((USHORT*)buf+6) = BUT2;
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 Reset = Convert::ToInt32(ResetValue->Text);
			 for (int i=0; i<=15; i++)
			 {
				buf[i]=0;
			 }
			 *((USHORT*)buf+7) = Reset;
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
			  X = Convert::ToInt32(XValue->Text);
			   *((USHORT*)buf) = X;
			  Y = Convert::ToInt32(YValue->Text);
			   *((USHORT*)buf+1) = Y;
			  Z = Convert::ToInt32(ZValue->Text);
			   *((USHORT*)buf+2) = Z;
			  RX = Convert::ToInt32(RXValue->Text);
			   *((USHORT*)buf+3) = RX;
			  ZR = Convert::ToInt32(ZRValue->Text);
			   *((USHORT*)buf+4) = ZR;
			  BUT1 = Convert::ToInt32(BUT1Value->Text);
			   *((USHORT*)buf+5) = BUT1;
			  BUT2 = Convert::ToInt32(BUT2Value->Text);
			   *((USHORT*)buf+6) = BUT2;

			   
				int send_RetVal = sendto(sd, buf, 16, NULL, (SOCKADDR*)&addr, sizeof(addr));

				if (send_RetVal == SOCKET_ERROR)
				{
				printf("An error occured while send operation ");
				getchar();
				}

		 }
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ tbstring = textstring -> Text;
			 std::string tbstr;
			 tbstr = marshal_as<std::string>( tbstring );
			 char *xbuf = (char*)tbstr.c_str();
			 sendto(sd, xbuf, 2048, NULL, (SOCKADDR*)&addr, sizeof(addr));
		 }
};
}

//std::string stdText1;
//2	String^ systemText1 = textBox1->Text;
//3	MarshalString(systemText1, stdText1);