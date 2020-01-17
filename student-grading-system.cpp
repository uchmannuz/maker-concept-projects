//============================================================================
// Name        : student-grading-system.cpp
// Author      : Uchenna Nwanyanwu
// Version     :
// Copyright   : Your copyright notice
// Description : Student Grading System in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

string trim(const string& str, const string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

void printGradeDetermination()
{
	cout << "***************** Grade Determination *****************\n";
	cout << "A = 100 – 90 points \nB = 89 – 80 points \nC = 79 – 70 points \nD = 69 – 60 points \nF = 59 points or below \n\n";
}

string getGrade(double score)
{
	if(score >= 90) return "A";
	else if(score >= 80 && score < 90) return "B";
	else if(score >= 70 && score < 80) return "C";
	else if(score >= 60 && score < 70) return "D";
	return "F";
}

void printGradingMatrix()
{
	cout << "***************** Grading Matrix ***************\n";
	cout << "************************************************\n";
	cout << "* Instrument               * Total             *\n";
	cout << "************************************************\n";
	cout << "* Assignment               * 10                *\n";
	cout << "* Quiz                     * 20                *\n";
	cout << "* Mid-Term Exam            * 30                *\n";
	cout << "* Class Participation      * 5                 *\n";
	cout << "* Final Exam               * 35                *\n";
	cout << "************************************************\n";
	cout << "* Total                    * 100               *\n";
	cout << "************************************************\n\n";
}

void printDataEntryFormat()
{
	cout << "**************** Please follow the format below to enter Student's data and scores **************** \n";
	cout << "**************** Enter each Student's scores line by line following the format below. Type End and hit Enter key once you are done to compute the grades**************** \n";
	cout << "**************** The Courses can be entered in any order but the slash, in between Student's name and courses and spaces between scores must be followed in order to get the desired results.**************** \n";
	cout << "**************** Student Full Name/Course Code1, Assignment Quiz Mid-Term ClassParticipation FinalExam/Course Code2, Assignment Quiz Mid-Term ClassParticipation FinalExam/...**************** \n\n";
	cout << "For Example: To enter Sadio Mane and Christian Pulisic's COMM 1003, COMP 1011 and COMP 1013 scores \n\n";
	cout << "Sadio Mane/COMM 1003, 9 18 27 5 34/ COMP 1011, 8.5 19 29 5 33.8/ COMP 1013, 8 20 26 5 34 \n";
	cout << "Christian Pulisic/COMP 1011, 7 20 27 5 35/ COMM 1003, 8 19 28 5 33/ COMP 1013, 10 20 28 5 34.5 \n\n";
}

void printInformation()
{
	printGradeDetermination();
	printGradingMatrix();
	printDataEntryFormat();
}


unordered_map<string, vector<string>> getInputData()
{
	unordered_map<string, vector<string>> data;
	string line;
	getline(cin, line);
	while(line.compare("End") != 1)
	{
		size_t last = 0;
		size_t next = 0;
		vector<string> lineSplit;
		while ((next = line.find("/", last)) != string::npos)
		{
			lineSplit.push_back(trim(line.substr(last, next-last)));
			last = next + 1;
		}
		lineSplit.push_back(trim(line.substr(last)));
		string key = lineSplit.at(0);
		lineSplit.erase(lineSplit.begin() + 0);
		data[key] = lineSplit;
		getline(cin, line);
	}
	return data;
}

int main() {
	//Test Data
//	Sadio Mane/COMM 1003, 9 18 27 5 34/ COMP 1011, 8.5 19 29 5 33.8/ COMP 1013, 8 20 26 5 34
//	Christian Pulisic/COMP 1011, 7 20 27 5 35/ COMM 1003, 8 19 28 5 33/ COMP 1013, 10 20 28 5 34.5
//	End

	unordered_map<string, vector<double>> courseMap;
	unordered_map<string, unordered_map<string, double>> studentMap;

	unordered_map<string, vector<string>> data = getInputData();
	for(pair<string, vector<string>> element : data)
	{
		string studentName = element.first;
		vector<string> courses = element.second;
		unordered_map<string, double> studentCourses;

		for(string course : courses)
		{
			size_t last = 0;
			size_t next = course.find(",", last);
			string courseName = trim(course.substr(last, next-last));
			string courseScores = trim(course.substr(next + 1));
			istringstream ss(courseScores);
			double totalScore = 0.0;
		    do {
		        string score;
		        ss >> score;
		        totalScore += atof(score.c_str());
		    } while (ss);
		    studentCourses[courseName] = totalScore;

			if(courseMap.find(courseName) != courseMap.end())
			{
				courseMap[courseName].push_back(totalScore);
			}else
			{
				vector<double> v;
				v.push_back(totalScore);
				courseMap[courseName] = v;
			}
		}
		studentMap[studentName] = studentCourses;
	}

	unordered_map<string, double> avgMap;
	for(pair<string, vector<double>> p : courseMap)
	{
		int size = p.second.size();
		double total = 0.0;
		for(double score : p.second)
		{
			total += score;
		}
		double avg = total / size;
		avgMap[p.first] = avg;
	}

	for(pair<string, unordered_map<string, double>> student : studentMap)
	{
		string studentName = student.first;
		cout << "Student Name:\t" << studentName << "\n";
		cout << "Number of Courses:\t" << student.second.size() << "\n";
		for(pair<string, double> courses : student.second)
		{
			cout << "Course Name: " << courses.first << ",\t Score: " << courses.second << ",\t Class Average: " << avgMap[courses.first] << "\n";
		}
		cout << "\n";
	}
	return 0;
}
