# BayesClassifier
A Bayesian Classifier in C

Please click on the folder to see the code. 

This program is based on bayes rule and classifies a number of randomly generated measurements to a number of classes. The input is an input file called testData.dat which asks for the number of repetitions (How many times the program is run), the number of classes, the number of measurements, the seed for randomization, and the percentages for each class given 1 after the other in a notepad file.

The program first randomly assigns each of the measurements a class keeping in mind the percentages provided by the user and then assigns these measurements to a class using bayes rule. The probability of correct identification is the output and is determined by a confusion matrix. There is also an option for the user to enter a perturbation that will perturb the results of the experiment by a certain amount depending on what the user chooses.

This program is based in the central file Bayes_Classifier_3.c where all the subroutines are imported and used. Finally, a debugging feature is currently active as uploaded and can be turned of by changing the variable TODEBUG to 0 in Bayes_Classifier_3.c

This is part of a longer project and is very much a work in progress.
