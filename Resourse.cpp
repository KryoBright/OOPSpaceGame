using namespace std;

class Resourse
{
	public:
		double res_am;
		double res_val;
		string res_name;//Is string,adding ability to create custom resourses
		Resourse extract(double amount)//Function to take part from resourse
		{
			if(amount<res_am)
			{
				res_am-=amount;
				return Resourse(res_name,amount,res_val);
			}
			else
			{
				Resourse tmp=Resourse(res_name,res_am,res_val);
				res_am=0;
				res_val=0;
				res_name="Dummy";//Special resourse without value,which used to show "nothing"
				return tmp;
			}
		}

		Resourse(string name,double amount,double value)//Constuctor
		{
			res_name=name;
			res_am=amount;
			res_val=value;
		}
};
