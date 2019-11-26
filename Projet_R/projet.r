getwd()

setwd('/home/sdv/l3bi/aspampinato/Documents/TPR')

tabveter = read.table(file = "veteran.txt", header = TRUE, dec = ",")

tabveter$traitement = as.factor(tabveter$typeTraitement)
tabveter$cellule = as.factor(tabveter$typeCellule)
tabveter$mort = as.factor(tabveter$mort)
tabveter$therapie = as.factor(tabveter$precedenteTherapie)

hist(tabveter$scoreKarnofsky)
hist(tabveter$joursSurvie)
hist(tabveter$age)
hist(tabveter$moisDepuisDiagnostic)

summary(tabveter)

tabveter

#tabveter[,9] = ifelse(tabveter$typeTraitement == 1, "standard", "experimental")

#if(tabveter$typeCellule == 1){
#  "squameuse"
#} else if(tabveter$typeCellule == 2){
#  "petite"
#} else if(tabveter$typeCellule == 3){
#  "adeno"
#} else{
#  "grande"
#}

tabSurvieStandard = tabveter$joursSurvie[which(tabveter$typeTraitement == 1)]
tabSurvieSExperimental = tabveter$joursSurvie[which(tabveter$typeTraitement == 2)]

varianceStandard = var(tabSurvieStandard) / length(tabSurvieStandard)
varianceStandard
varianceExperimental = var(tabSurvieSExperimental) / length(tabSurvieSExperimental)
varianceExperimental

var.test(tabveter$joursSurvie~tabveter$traitement)

t.test(tabveter$joursSurvie~tabveter$traitement, var.equal = 1)

boxplot(tabveter$joursSurvie~tabveter$traitement)

#####

var.test(tabveter$scoreKarnofsky~tabveter$traitement)

t.test(tabveter$scoreKarnofsky~tabveter$traitement, var.equal = 1)

#####

var.test(tabveter$age~tabveter$traitement)

t.test(tabveter$age~tabveter$traitement, var.equal = 1)

#####

var.test(tabveter$joursSurvie~tabveter$precedenteTherapie)

t.test(tabveter$joursSurvie~tabveter$precedenteTherapie, var.equal = 1)

##### SIGNIFICATIF !!!!!

var.test(tabveter$moisDepuisDiagnostic~tabveter$precedenteTherapie)

t.test(tabveter$moisDepuisDiagnostic~tabveter$precedenteTherapie, var.equal = 1)

boxplot(tabveter$moisDepuisDiagnostic~tabveter$precedenteTherapie)

#####

var.test(tabveter$scoreKarnofsky~tabveter$precedenteTherapie)

t.test(tabveter$scoreKarnofsky~tabveter$precedenteTherapie, var.equal = 1)

#####

plot(tabveter$joursSurvie, tabveter$age)

cor.test(tabveter$joursSurvie, tabveter$age)

##### SIGNIFICATIF !!!!!

plot(tabveter$joursSurvie, tabveter$scoreKarnofsky)

cor.test(tabveter$joursSurvie, tabveter$scoreKarnofsky)

##### SIGNIFICATIF !!!!!

plot(tabveter$joursSurvie, tabveter$scoreKarnofsky)

cor.test(tabveter$joursSurvie, tabveter$scoreKarnofsky)


data.frame(tabveter$scoreKarnofsky, RgT = rank(tabveter$scoreKarnofsky), tabveter$joursSurvie, RgP=rank(tabveter$joursSurvie), Diff = rank(tabveter$scoreKarnofsky)-rank(tabveter$joursSurvie), Diffaucarre=(rank(tabveter$scoreKarnofsky)-rank(tabveter$joursSurvie))^2)

model = lm(tabveter$scoreKarnofsky ~ tabveter$joursSurvie)

#Anova
#tabSurvieSquameuse = tabveter$joursSurvie[which(tabveter$typeCellule == 1)]
#tabSurviePetite = tabveter$joursSurvie[which(tabveter$typeCellule == 2)]
#tabSurvieAdeno = tabveter$joursSurvie[which(tabveter$typeCellule == 3)]
#tabSurvieGrande = tabveter$joursSurvie[which(tabveter$typeCellule == 4)]

cellSurvie = data.frame(tc = tabveter$typeCellule, js = tabveter$joursSurvie)
summary(tabveter$joursSurvie)                                       
                                     

bartlett.test(cellSurvie$js ~ cellSurvie$tc)

######

summary(aov(typeCellule ~ joursSurvie, data = tabveter))

######

summary(aov(typeCellule ~ scoreKarnofsky, data = tabveter))

######

summary(aov(typeCellule ~ age, data = tabveter))

######

summary(aov(typeCellule ~ moisDepuisDiagnostic, data = tabveter))

######



