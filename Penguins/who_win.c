int who_win(int point1, int point2, int point3, int point4, int point5, int point6)        //1player points, 2 player points ...
{
	int pl[6];
	int i;
	pl[0]= point1;
	pl[1]= point2;
	pl[2]= point3;
	pl[3]= point4;
	pl[4]= point5;
	pl[5]= point6;
	int max=pl[0];
	int imax=0;

	for(i=0; i<6; i++)
	{
    		if(pl[i]>=max)
    		{
        		max=pl[i];
        		imax=(i+1);
    		}
	}
return imax;
}
