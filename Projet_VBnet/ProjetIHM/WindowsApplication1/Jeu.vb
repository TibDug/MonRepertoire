Module Jeu
    Dim temps As Integer = 60

    Dim tempsPartie As Integer

    Dim nbJoueurs As Integer = 0

    Public Function getTemps() As Integer
        Return temps
    End Function

    Public Sub setTemps(nouvTemps As Integer)
        temps = nouvTemps
    End Sub

    Public Function getTempsPartie() As Integer
        Return tempsPartie
    End Function

    Public Sub setTempsPartie(nouvTemps As Integer)
        tempsPartie = nouvTemps
    End Sub

    Public Sub incJoueurs()
        nbJoueurs = nbJoueurs + 1
    End Sub

    Public Function getNbJoueurs() As Integer
        Return nbJoueurs
    End Function

End Module
