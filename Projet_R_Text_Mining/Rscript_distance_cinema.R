

## install.packages("tokenizers")
## install.packages("stopwords")


library(tokenizers)
library(stopwords)
 
## ETAPE 1 ##

normaliser  <- function(vec_lines){
    text_total = ""
    for(i in c(1:length(vec_lines))){
        text_total = paste(text_total,vec_lines[i])
    }
    return(text_total)
}

TerminatorLecture = readLines("script_Terminator.txt")
TerminatorLecture

TerminatorNormalise = normaliser(TerminatorLecture)
TerminatorNormalise

## ETAPE 2 ##

token_TerminatorAvecStopWords = tokenize_words(TerminatorNormalise)
token_TerminatorAvecStopWords

token_Terminator = tokenize_words(TerminatorNormalise,stopwords=stopwords::stopwords("en"))
token_Terminator

## ETAPE 3 ##
 
token <- function(text){
    token = tokenize_word_stems(text,stopwords=stopwords::stopwords("en"))
    token = token[[1]]
    return(token)
}

token_ajuster <- function(token){
    token_doublon = which(duplicated(token))
    token_ajuster = token[-token_doublon]
    return (token_ajuster)
}

token_TerminatorStem = token(TerminatorNormalise)
token_TerminatorStem

token_TerminatorStemSansRep = token_ajuster(token_TerminatorStem)
token_TerminatorStemSansRep


## ETAPE 4 ##

token_DieHardStem = token(normaliser(readLines("script_DieHard.txt")))
token_DieHardStemSansRep = token_ajuster(token_DieHardStem)
token_DieHardStemSansRep

######

token_PrettyWommanStem = token(normaliser(readLines("script_PrettyWoman.txt")))
token_PrettyWommanStemSansRep = token_ajuster(token_PrettyWommanStem)
token_PrettyWommanStemSansRep

######

token_total = c(token_TerminatorStem,token_DieHardStem,token_PrettyWommanStem)
token_totalSansRep = token_ajuster(token_total)
token_totalSansRep

## ETAPE 5 ##

frequence  <- function(token_ajuster,token){
    poderation = c()
    for(i in c(1:length(token_ajuster))){
        poderation[i] = sum(token==token_ajuster[i])
    }
    max_pond = max(poderation)
    poderation_ratio = poderation/max_pond
    return(poderation_ratio)
}

freq_Terminator = frequence(token_totalSansRep,token_TerminatorStem)
freq_Terminator

######

freq_DieHard  = frequence(token_totalSansRep,token_DieHardStem)
freq_DieHard

######

freq_PrettyWoman = frequence(token_totalSansRep,token_PrettyWommanStem)
freq_PrettyWoman

## ETAPE 6 ##

data = data.frame(header = token_totalSansRep,freq_Terminator,freq_DieHard,freq_PrettyWoman)
data

# Calcul des fréquences des mots dans le corpus

for(i in c(1:length(token_totalSansRep))){
    cmpt=0
    for(j in c(2:4)){
        if(data[i,j]>0){
            cmpt = cmpt+1
        }
    }
    data[i,5]=cmpt
    data[i,6]=log(3/cmpt)
}

data

for(i in c(7:9)){
    j = i - 5
    for(k in c(1:length(token_totalSansRep))){
        data[k,i] = data[k,j]*data[k,6]
    }
}

data



## ETAPE 7 ##

distance  <- function(ligneT1,ligneT2){
    sumAB = 0
    sumA2 = 0
    sumB2 = 0
    for(i in c(1:length(ligneT1))){
        sumAB = sumAB + (ligneT1[i]*ligneT2[i])
        sumA2 = sumA2 + ligneT1[i]*ligneT1[i]
        sumB2 = sumB2 + ligneT2[i]*ligneT2[i]
    }
    denominateur = sqrt(sumA2)*sqrt(sumB2)
    sorti = sumAB/denominateur
    return(sorti)
}
 
distance(data[,7],data[,8])
distance(data[,7],data[,9])
distance(data[,8],data[,9])

