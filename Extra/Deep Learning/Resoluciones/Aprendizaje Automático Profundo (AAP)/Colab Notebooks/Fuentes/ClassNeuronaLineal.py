import numpy as np
import time

from matplotlib import pylab as plt
from IPython import display

from grafica import *

class NeuronaLineal(object):
    """
    Parameters
    ------------
    alpha : float
        Learning rate (between 0.0 and 1.0)
    n_iter : int
        Passes over the training dataset.
    random_state : int
        Random number generator seed for random weight initialization.
    draw : int
        1 si dibuja -  0 si no
    title : list con 2 elementos
        titulos de los ejes - sólo 2D
        
    Attributes
    -----------
    w_ : 1d-array
        Weights after fitting.
    errors_ : list
        Number of misclassifications (updates) in each epoch.
    """
    def __init__(self, alpha=0.01, n_iter=50, cotaE=10E-07, random_state=None, draw=0, title=['X1','X2']):
        self.alpha = alpha
        self.n_iter = n_iter
        self.cotaE = cotaE
        self.random_state = random_state #-- asignar el valor 1 para fijar la semilla por defecto es aleatorio
        self.draw = draw
        self.title = title

    def fit(self, X, y):
        """Fit training data.
        Parameters
        ----------
        X : {array-like}, shape = [n_examples, n_features]
            Training vectors, where n_examples is the number of
            examples and n_features is the number of features.
        y : array-like, shape = [n_examples]
            Target values.
        Returns
        -------
        self : object
        """

        # graficar la recta
        if (self.draw):
            ycol=y.reshape(-1,1)
            puntos = np.concatenate((X,ycol), axis=1)
            T = np.zeros(X.shape[0])
            
        rgen = np.random.RandomState(self.random_state)

        # self.w_ = rgen.normal(loc=0.0, scale=0.01,size=1 + X.shape[1])

        self.w_ = rgen.uniform(-0.5, 0.5, size= X.shape[1]) 
        self.b_ = rgen.uniform(-0.5, 0.5)
        self.errors_ = []
        ph = 0  # manejador de la recta mientras se dibuja
        ErrorAnt = 0
        ErrorAct = 1
        
        i = 0
        while ((i<self.n_iter) and (np.abs(ErrorAnt- ErrorAct) > self.cotaE)):
            ErrorAnt = ErrorAct
            ErrorAct = 0
            for xi, target in zip(X, y):
                
                errorXi = (target - self.predict(xi))
                update = self.alpha * errorXi
                self.w_ += update * xi
                self.b_ += update
                
                ErrorAct += errorXi**2
                
            self.errors_.append(ErrorAct)
            
            # graficar la recta
            if (self.draw):
                ph = dibuPtosRecta(puntos,T, np.array([self.w_, -1],dtype=object), self.b_, self.title, ph)
            
            i = i + 1
        return self

    def net_input(self, X):
        """Calculate net input"""
        return np.dot(X, self.w_) + self.b_

    def predict(self, X):
        """Return class label after unit step"""
        return self.net_input(X) 