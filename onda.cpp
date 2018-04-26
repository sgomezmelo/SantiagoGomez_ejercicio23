#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double u_next(double c, double dt, double dx, double u_presente, double u_tanterior, double u_xanterior, double u_xnext){
  double u = pow(c*dt/dx,2)*(u_xnext - 2*u_presente+u_xanterior) + 2*u_presente - u_tanterior;
  return u;
}

int main(){
  double c = 0.1;
  double dx = 0.001;
  double dt = 0.01;
  double L = 1;
  double pi = 3.14159265359;
  int n_x = L/dx + 1;

  double *u_ant = new double[n_x];
  double *u_pres = new double[n_x];
  double *u = new double[n_x];
  double *x = new double[n_x];

  for(int i = 0; i<n_x;i++){
    x[i] = i*dx;
    if((i == 0) || (i == n_x -1)){
      u_ant[i] = 0;
    }
    else{
    u_ant[i] = sin(x[i]*2*pi);
    }
  }
  for(int i = 0; i<n_x;i++){
    if((i == 0) || (i == n_x-1)){
      u_pres[i] = 0;
    }
    else{
    u_pres[i] = pow(c*dt/dx,2)*(u_ant[i+1] + u_ant[i-1] - 2*u[i])/2 + u[i];
    }
  }

   for(int i = 0; i<n_x;i++){
     cout << x[i] << " " << u_ant[i] << endl;
    }

  int j = 1;

  while(u_pres[n_x/4] > -0.99){
   
    for(int i = 0; i<n_x;i++){
     if((i == 0) || (i == n_x-1)){
      u[i] = u_pres[i];
      }
     else{
       u[i] = u_next(c,dt,dx,u_pres[i],u_ant[i],u_pres[i-1],u_pres[i+1]);
      }
    }

    if((u_ant[n_x/4] > 0.4999) && (u[n_x/4] < 0.49)){
      cout << j << " " << j*dt << endl;
      for(int i = 0; i<n_x;i++){
	cout << x[i] << " " << u_pres[i] << endl;
      }
    }

    if((u_ant[n_x/4] > -0.5) && (u[n_x/4] < -0.5)){
      cout << j << " " << j*dt << endl;
      for(int i = 0; i<n_x;i++){
	cout << x[i] << " " << u_pres[i] << endl;
      }
      }

    for(int i = 0; i<n_x;i++){
      u_ant[i] = u_pres[i];
      u_pres[i] = u[i];
    }

    j = j+1;
    
  }

  cout << j << " " << j*dt << endl;
   for(int i = 0; i<n_x;i++){
     cout << x[i] << " " << u[i] << endl;
    }

  return 0;
  
}
