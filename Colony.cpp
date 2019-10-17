class Colony:public ResourseContainer
{
	private:
		vector<Building>builds;
		void abst()
		{
			//not abstract anymore
		}
	public:
		ObjectInSpace *par;//TODO:Move into constructor and private,since colonies don't move
		bool putResourse(ObjectInSpace &dest,string name,double amount)//puts resourse into ships or home planet
		{
			if ((abs(dest.getX()-par->getX())<0.1)and(abs(dest.getY()-par->getY())<0.1))
			{
				if (getAmount(name)>amount)
				{
					dest.store(takeRes(name,amount));
					cout<<"Resourse moved succesfully"<<endl;
					return true;
				}
			}
			cout<<"Failed moving Resourse";
			return false;
		}
		bool takeResourse(ObjectInSpace &dest,string name)//takes resourse into ships or home planet
		{
			if ((abs(dest.getX()-par->getX())<0.1)and(abs(dest.getY()-par->getY())<0.1))
			{
				dest.takeRes(name,dest.getAmount(name));
				cout<<"Resourse taken!"<<endl;
				return true;
			}
			else
			{
				cout<<"Failed.Do you even know,where objects are?";
				return false;
			}
		}

		SpaceShip createShip(long num)//builds spaceship
		{
			if ((getAmount("Human")>10)and(getAmount("Iron")>100)and(getAmount("Liquid")>10))
			{
				takeRes("Human",10);
				takeRes("Iron",100);
				takeRes("Liquid",10);
				SpaceShip tmp(num);
				tmp.setCordinate(par->getX(),par->getY());
				cout<<"Ship number "<<num<<" is ready!"<<endl;
				return tmp;
			}
			cout<<"Failed to create ship";
			return false;
		}

		void buildFabric(string cons_res,string gen_res="Dumnmy")//builds factory.TODO:rename fabric to factory
		{
			if ((getAmount(cons_res)>20)and(getAmount("Humans")>5))
			{
				Fabric tmp(cons_res,gen_res,cons_res+"-"+gen_res+" converter");
				builds.push_back(tmp);
				cout<<"Build "<<cons_res<<"-"<<gen_res<<" converter"<<" succsefully"<<endl;
			}
			else
			{
				cout<<"Not enought resourses to built "<<cons_res<<"-"<<gen_res<<" converter"<<endl;
			}
		}

		void buildGasStation()//builds Gas Station
		{
			GasStation tmp(par->getX(),par->getY());
			builds.push_back(tmp);
		}

		void gameCycle() //imitates time passage
		{
			long i=0;
			while (i<builds.size())
			{
				builds[i].produce();
				i++;
			}
		}
};
