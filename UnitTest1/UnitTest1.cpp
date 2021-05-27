#include "pch.h"
#include "CppUnitTest.h"
#include"..\kursovaya\FordFulkerson.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(FordFulkerson1)
		{
			FordFulkerson a;
			ofstream out;
			out.open("graph.txt");
			if (out.is_open())
			{
				out << "S B 6";
				out << endl;
				out << "S A 10";
				out << endl;
				out << "A B 4";
				out << endl;
				out << "A E 7";
				out << endl;
				out << "B C 11";
				out << endl;
				out << "B D 8";
				out << endl;
				out << "C T 8";
				out << endl;
				out << "D T 5";
				out << endl;
				out << "E T 8";
				out << endl;
				out << "E D 4";
			}
			out.close();
			int result = a.alghoritm("graph.txt");
			int sup = 16;
			Assert::AreEqual(result, sup);
		}
		TEST_METHOD(FordFulkerson2)
		{
			FordFulkerson a;
			ofstream out;
			out.open("graph.txt");
			if (out.is_open())
			{
				out << "S B 5";
				out << endl;
				out << "S D 7";
				out << endl;
				out << "D F 13";
				out << endl;
				out << "B G 4";
				out << endl;
				out << "G F 6";
				out << endl;
				out << "F T 15";
			}
			out.close();
			int result = a.alghoritm("graph.txt");
			int sup = 11;
			Assert::AreEqual(result, sup);
		}
		TEST_METHOD(FordFulkerson3)
		{
			FordFulkerson a;
			ofstream out;
			out.open("graph.txt");
			if (out.is_open())
			{
				out << "S B 5";
				out << endl;
				out << "B T 3";
				out << endl;
				out << "S D 2";
				out << endl;
				out << "D T 5";

			}
			out.close();
			int result = a.alghoritm("graph.txt");
			int sup = 5;
			Assert::AreEqual(result, sup);
		}
	};
}
