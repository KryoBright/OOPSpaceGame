class Fabric:public Building
{
	public:
		void produce()
		{
			if (status)
			{
				passiveSpend();
				Resourse tmp(gen_res,0.009,(homeColony->takeRes(gen_res,0).res_val));//produces more resourse with more value
				homeColony->store(tmp);//all resurse get sent to home colony
			}
		}
		Fabric(string cres,string gres,string bname)
		{
			con_res=cres;
			gen_res=gres;
			name=bname;
		}

};
