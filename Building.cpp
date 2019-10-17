class Building:public ResourseContainer
{
	protected:
		bool status=false;//working or not
		string con_res;//consumed resourse
		string gen_res;//generated resourse
		ResourseContainer *homeColony;
		string name;//Buildings have custom names
		void abst()
		{
			//needs to be not abstract to make vector out of it
			//can't figure out,how to make this abstract and have vector of it
		}
		void passiveSpend()//resource use over time
		{
			if (status)
			{
				takeRes(con_res,0.01);
				if (getAmount(con_res)<1)
				{
					store(homeColony->takeRes(con_res,1));//can request additional resourses from colony
				}
				if (getAmount(con_res)<1)
				{
					status=false;//stops work if out of resourse
				}
			}
		}
	public:
		void startWork()
		{
			status=true;
		}
		void stopWork()
		{
			status=false;
		}
		void produce()//will be overriden
		{
			//this is Dummy
		}

};
