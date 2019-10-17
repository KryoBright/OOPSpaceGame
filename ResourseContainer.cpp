class ResourseContainer
{
	private:
		vector<Resourse>cont;//Dinamic container for resourses.Never sorted due to small number of items
		virtual void abst()=0;//Makes class abstract
	public:
		void store(Resourse res)//Function to put resourse into container
		{
			if (res.res_name!="Dummy")//You can't put nothing
			{
				bool put=false;
				long i=0;
				while ((i<cont.size())and(!put))//prevents unnecessary duplicates
				{								
					if (cont[i].res_name==res.res_name)
					{	//resourse with same name can have different cost(purity,quality,etc)
						cont[i].res_val=(cont[i].res_val*cont[i].res_am+res.res_val*res.res_am)/(cont[i].res_am+res.res_am);
						cont[i].res_am+=res.res_am;
						put=true;
					}
					else
					{
						i++;
					}
				}
				if (!put)
				{
					cont.push_back(res);
				}
			}
		}
		Resourse takeRes(string name,double amount)//Function to get resourse from cont
		{
			bool got=false;
			long i=0;
			while ((i<cont.size())and(!got))
			{
				if (cont[i].res_name==name)
				{
					if (cont[i].res_am>=amount)
					{
						cont[i].res_am-=amount;
						double tmp_val=cont[i].res_val;
						if (cont[i].res_am==0)//Destroys resourse,if you take all of it
						{
							cont.erase(cont.begin()+i);
						}
						return Resourse(name,amount,tmp_val);
					}
				}
				i++;
			}
			Resourse tmp=Resourse("Dummy",0,0);//Gives nothing,if neccesary resourse not found in sufficent amount
			return tmp;
		}

		double getAmount(string name)//retern amount of resourse
		{
			long i=0;
			while (i<cont.size())
			{
				if (cont[i].res_name==name)
				{
					return cont[i].res_am;
				}
				i++;
			}
			if (name=="Dummy")//You always have lots of nothing
			{
				return 999;
			}
			return 0;
		}

		vector<string> getNames()//returns vector of stored resourses' names
		{
			vector<string>tmp;
			long i=0;
			while (i<cont.size())
			{
				tmp.push_back(cont[i].res_name);
				i++;
			}
			return tmp;
		}

		double getSummCost()//returns summarized cost of all resourses in container
		{
			double sum=0;
			long i=0;
			while (i<cont.size())
			{
				sum+=cont[i].res_am*cont[i].res_val;
				i++;
			}
			return sum;
		}
};

