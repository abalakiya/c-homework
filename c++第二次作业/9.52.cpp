// Copyright [2019] <Copyright zhengxin>

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
 
int priority(string opt)
{
	int p = 0;
	if(opt == "(")
		p = 1;
	if(opt == "+" || opt == "-")
		p = 2;
	if(opt == "*" || opt == "/")
		p = 3;
	return p;
}
 
void calculate(stack<int> &opdstack, string opt)
{
	if(opt == "+")
	{
		int ropd = opdstack.top();
		opdstack.pop();
		int lopd = opdstack.top();
		opdstack.pop();
		int result = lopd + ropd;
		opdstack.push(result);
	}
	if(opt == "-")
	{
		int ropd = opdstack.top();
		opdstack.pop();
		int lopd = opdstack.top();
		opdstack.pop();
		int result = lopd - ropd;
		opdstack.push(result);
	}
	if(opt == "*")
	{
		int ropd = opdstack.top();
		opdstack.pop();
		int lopd = opdstack.top();
		opdstack.pop();
		int result = lopd * ropd;
		opdstack.push(result);
	}
	if(opt == "/")
	{
		int ropd = opdstack.top();
		opdstack.pop();
		int lopd = opdstack.top();
		opdstack.pop();
		int result = lopd / ropd;
		opdstack.push(result);
	}
}
  
int calcuExpression(vector<string> vec)
{
	stack<int> stack_opd;
	stack<string> stack_opt;
	
	for(int i = 0; i != vec.size(); ++i)
	{
		string token = vec[i];
		if(token == "+" || token == "-" || token == "*" || token == "/")
		{
			if(stack_opt.size() == 0)
				stack_opt.push(token);
			else
			 {
			 	int token_p = priority(token);
			 	string top_opt = stack_opt.top();
			 	int opt_p = priority(top_opt);
			 	if(token_p > opt_p)
			 		stack_opt.push(token);
			 	else
			 	  {
			 	  	while(token_p <= opt_p)
			 	  	{
			 	  		stack_opt.pop();
			 	  		calculate(stack_opd, top_opt);
			 	  		if(stack_opt.size() > 0)
			 	  		{
			 	  			top_opt = stack_opt.top();
			 	  			opt_p = priority(top_opt);
						   }
						else
						 	break;
					  }
					  stack_opt.push(token);
				   }
			 }
		}
		
		else if(token == "(")
			stack_opt.push(token);
		else if(token == ")")
		{
			while(stack_opt.top() != "(")
			{
				string top_opt = stack_opt.top();
				calculate(stack_opd,top_opt);
				stack_opt.pop();
			}
			stack_opt.pop();
		}
		else
		  stack_opd.push(atoi(token.c_str()));  
	}
	
	while(stack_opt.size() != 0)
	{
		string top_opt = stack_opt.top();
		calculate(stack_opd,top_opt);
		stack_opt.pop();
	}
	return stack_opd.top();
}
 
int main() {
	vector<string> tokens =  {"(","1","+","2",")","*","3","/","(","2","-","1",")"};
	for(auto i = 0; i != tokens.size(); ++i)
    cout << tokens[i] << " ";
    cout << endl;
    cout << calcuExpression(tokens) << endl;
	return 0;
}

