#include<stdio.h> 
int main() 
{ int time_quantum=4;
  int count,n,i,j,k,c1,c2,c3;
  int time=0;
  printf("\n\nEnter the Total number of Process:\t "); 
  scanf("%d",&n);
  int waiting_time,turn_around_time,priority[n],burst_time[n],rt[n],t[n],rt1[n],rt2[n],rt3[n],p1[n],p2[n],p3[n],q1[n],q2[n],q3[n];
  for(count=0;count<n;count++) 
  { 
    printf("Enter Priority and Burst Time for Process Process Number %d :",count+1); 
   scanf("%d",&priority[count]); 
    scanf("%d",&burst_time[count]); 
    rt[count]=burst_time[count]; 
  }
  
  int max=0;
  int a;	
for(i=0;i<n;i++){
	if(priority[i]>max){
		max=priority[i];
		a=i;
	}
}
int r=priority[a]/3;
int p=2*r;

for(i=0,j=0,k=0,count=0;count<n;count++){
	if(priority[count]<=r){
		p1[i]=priority[count];
		rt1[i]=burst_time[count];
		q1[i]=count;
		i++;
		c1=i;
	}
	else if(priority[count]<=p && priority[count]>r){
		p2[j]=priority[count];
		rt2[j]=burst_time[count];
		q2[j]=count;
		j++;
		c2=j;
	}
	else{
		p3[k]=priority[count];
		rt3[k]=burst_time[count];
		q3[k]=count;
		k++;
		c3=k;
	}
}




	
		
		int flag=1, flag1=1,flag2=1,flag3=1;
		while(flag<=n){
		
r:;
int c=0;
	while (flag1<=c1)
{
int a;
for(a=0;a<c1;a++){
if(rt1[a]>time_quantum && (c+time_quantum)<=10){
	time=time+time_quantum;
	rt1[a]=rt1[a]-time_quantum;
	c+=time_quantum;
}
else if(rt1[a]<=time_quantum && rt1[a]!=0 && (c+rt1[a])<=10){
time=time+rt1[a];
c+=rt1[a];
	rt1[a]=0;
	t[q1[a]]=time;
	flag1=flag1+1;
	flag=flag+1;
}
else if((c+rt1[a])>10 || (c+time_quantum)>10){
	time=time+10-c;
	rt1[a]=rt1[a]-10+c;
	goto p;
}
}
}




p:;

c=0;
while(flag2<=c2){

for(count=0;count<c2;count++)
{
int min=100;	
for(i=0;i<c2;i++){
	if(p2[i]<min && rt2[i]!=0){
		min=p2[i];
		a=i;
	}
}
if((c+rt2[a])<=10){

time=time+rt2[a];
c=c+rt2[a];
rt2[a]=0;
t[q2[a]]=time;
flag2=flag2+1;
flag=flag+1;
}
else if((c+rt2[a])>10){
time=time+10-c;
rt2[a]=rt2[a]-10+c;
goto f;	
}
}
}




f:;
c=0;
while(flag3<=c3){

for(count=0;count<c3;count++){
	if((c+rt3[count])<=10 && rt3[count]!=0){
		time=time+rt3[count];
		c=c+rt3[count];
		rt3[count]=0;
		t[q3[count]]=time;
		flag3=flag3+1;
		flag=flag+1;
	}
	else if((c+rt3[count])>10){
		time=time+10-c;
		rt3[count]=rt3[count]-10+c;
		goto r;
	}
	
	
}
}

}
printf("\n\nProcess\t    Burst Time  |    Priority   |Turnaround Time|Waiting Time\n\n");
for (count=0;count<n;count++){ 
      printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",count+1,burst_time[count],priority[count],t[count],t[count]-burst_time[count]); 
  //    waiting_time+=time-arrival_time[count]-burst_time[count]; 
    //  turn_around_time+=time-arrival_time[count]; 
      
}

}
