int Do[7]={3,4,5,6,7,8,13};
int ai[5];
int aitd[5];
int ub[]={0,0,0,0,0};
int lb[]={500,500,500,500,500};
int cv;int k,pcv;
int perr=0;int pwma,pwmb,pwmm=255;
float kp=0.19,ki=0.00008,kd=0.05;
void Sense();
void pidCalc();
void Work();
void Forward();
void setup(){
	Serial.begin(9600);
	for(int i=0;i<7;i++){
		pinMode(Do[i],OUTPUT);
	}
}
void loop(){
	digitalWrite(Do[6],HIGH);
	delay(25);
	Sense();
  pidCalc();
  Work();
}
void Sense(){
	ai[0]=analogRead(A1);
	ai[1]=analogRead(A2);
	ai[2]=analogRead(A3);
	ai[3]=analogRead(A4);
	ai[4]=analogRead(A5);
  
  for(int i=0;i<5;i++){
      if(ai[i]>ub[i]){ub[i]=ai[i];}
      if(ai[i]<lb[i]){lb[i]=ai[i];}

      ai[i]= map(ai[i],lb[i],ub[i],0,255);
  }
  ai[3]=(ai[3]>150)?1:0;

  if
  
  /*if(ai[3]==1){
      if(ai[3]==1)k=(-ai[4]*3-ai[0]+ai[1]+ai[2]*3);
      if((ai[0]>60||ai[1]>60||ai[2]>60||ai[4]>60||ai[3]==1))
      cv =k*ai[3]+(1-ai[3])*(((ai[0]+ai[4])>(ai[2]+ai[1]))?(k-(+(255-ai[4])*3+(255-ai[0]))):((255-ai[1])+(255-ai[2])*3+k));
      else cv=1800*(pcv/abs(pcv));
      pcv=cv;
    }*/

    
    for(int i=0;i<5;i++){
        aitd[i]=(ai[i]>150)?1:0;  
    }
    
} 

void pidCalc(){
  int err = 0 - cv;
  float pwm = err*kp + (perr+err)*ki + (err-perr)*kd;
  perr=err;
  //Serial.println(pwm);
  pwma=pwmm-pwm;pwmb=pwmm+pwm;
  pwma=(pwma>pwmm)?pwmm:pwma;
  pwmb=(pwmb>pwmm)?pwmm:pwmb; 
  pwma=(pwma<0)?0:pwma;
  pwmb=(pwmb<0)?0:pwmb;
  speedControl(pwma,pwmb);
}
void speedControl(int a, int b){

  analogWrite(Do[0], map(a,0,255,0,255));//246
  analogWrite(Do[3], map(b,0,255,0,250));
}
void Forward(){
  digitalWrite(Do[1],HIGH);
  digitalWrite(Do[2],LOW);
  digitalWrite(Do[4],HIGH);
  digitalWrite(Do[5],LOW);
}


