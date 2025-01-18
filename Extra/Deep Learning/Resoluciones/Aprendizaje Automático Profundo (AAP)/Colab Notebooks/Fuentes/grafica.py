import numpy as np
import time
from matplotlib import pylab as plt
from IPython import display

def dibuPtosRecta(entradas, salida, W, b, titulos=[], ph=0):
    if (entradas.shape[1]==2):
       #--- DIBUJA LOS EJEMPLOS EN EL FONDO -----
   
        plt.axis([min(entradas[:,0])-0.05, max(entradas[:,0])+0.05,min(entradas[:,1])-0.05, max(entradas[:,1])+0.05])
        plt.setp(plt.gca(), autoscale_on=False)
               
        clases=np.unique(salida)
        if len(clases)==2:
            plt.plot(entradas[salida==min(clases),0], entradas[salida==min(clases),1], 'bo')
            plt.plot(entradas[salida==max(clases),0], entradas[salida==max(clases),1], 'ro')
        else:
            plt.plot(entradas[:,0], entradas[:,1], 'ro')
        if (len(titulos)==2):
            plt.xlabel(titulos[0])
            plt.ylabel(titulos[1])
        
       #--- DIBUJA LA RECTA ---
        if (ph!=0):
            for p in ph:
                p.remove()
        
        X = np.array([min(entradas[:,0]), max(entradas[:,0])])
        Y = (-1)*(W[0]/W[1])*X - (b/W[1])
        ph = plt.plot(X,np.squeeze(np.asarray(Y)))

        display.clear_output(wait=True)
        display.display(plt.gcf())
        time.sleep(0.001)
    #time.sleep(1.0)
    #    plt.draw()
    #    plt.pause(.001)
        return(ph)
