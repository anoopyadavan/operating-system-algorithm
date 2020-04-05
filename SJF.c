#include<stdio.h>
int main()
{
	int pr_num,i,j,count=0,p_id[10],A_time[10],B_time[10],C_time[10],TAT[10],W_time[10];
	printf("Enter process number: ");
	scanf("%d",&pr_num);
	//printf("Enter arrival time: ");
	for(i=0;i<pr_num;i++)
	{
		printf("Enter process id: ");
		scanf("%d",&p_id[i]);
		printf("%d arrival time: ",p_id[i]);
		scanf("%d",&A_time[i]);
		printf("%d burst time: ",p_id[i]);
		scanf("%d",&B_time[i]);
	}
	void swap(int index)
	{
		for(j=index;j<pr_num-1;j++)
		{
			if(count>=A_time[index] && count>=A_time[j+1])
			{
				if(B_time[index]>=B_time[j+1])
				{
					int temp=B_time[index];
					B_time[index]=B_time[j+1];
					B_time[j+1]=temp;

					temp=A_time[index];
					A_time[index]=A_time[j+1];
					A_time[j+1]=temp;

					temp=p_id[index];
					p_id[index]=p_id[j+1];
					p_id[j+1]=temp;
				}
			}
		}
	}
	for(i=0;i<pr_num;i++)
	{
		swap(i);
		while(count!=A_time[i] && count<A_time[i])
			count++;
		swap(i);
		for(j=0;j<B_time[i];j++)
		{
			count++;
		}
		C_time[i]=count;
		TAT[i]=C_time[i]-A_time[i];
		W_time[i]=TAT[i]-B_time[i];
	}
	void arrange_PID()
	{
		for(i=0;i<pr_num-1;i++)
		{
			for(j=i+1;j<pr_num;j++)
			{
				if(p_id[i]>p_id[j])
				{
					int temp=B_time[i];
                                        B_time[i]=B_time[j];
                                        B_time[j]=temp;

                                        temp=A_time[i];
                                        A_time[i]=A_time[j];
                                        A_time[j]=temp;

                                        temp=p_id[i];
                                        p_id[i]=p_id[j];
                                        p_id[j]=temp;

					temp=C_time[i];
					C_time[i]=C_time[j];
					C_time[j]=temp;

					temp=TAT[i];
					TAT[i]=TAT[j];
					TAT[j]=temp;

					temp=W_time[i];
					W_time[i]=W_time[j];
					W_time[j]=temp;
				}
			}
		}
	}
	arrange_PID();
	printf("\n=====================================================================================\n");
	printf("PID\tArrival time\tBurst time\tCompletion time\t\tTAT\tWaiting time\n");
	for(i=0;i<pr_num;i++)
		printf("%d\t    %d\t\t  %d\t\t  %d\t\t\t %d\t   %d\n",p_id[i],A_time[i],B_time[i],C_time[i],TAT[i],W_time[i]);
	// calculating Average Turn around time and waiting time
	float total_TAT=0,total_WT=0;
	for(i=0;i<pr_num;i++)
	{
		total_TAT+=TAT[i];
		total_WT+=W_time[i];
	}
	printf("\nTotal Turn around time is: %.2f",total_TAT);
	printf("\nTotal Waiting time is: %.2f",total_WT);
	printf("\n\nAverage Turn around time is: %.2f",total_TAT/pr_num);
	printf("\nAverage Waiting time is: %.2f\n",total_WT/pr_num);
	return 0;
}
