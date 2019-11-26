Imports System.IO

Module Joueur
    Dim numJoueur As String
    Dim nom As String
    Dim highScore As Integer = 10000
    Dim nbParties As Integer = 0
    Dim tempsJoué As Integer = 0

    Public Sub newJoueur(newNom)
        Jeu.incJoueurs()
        numJoueur = Jeu.getNbJoueurs
        nom = newNom
        Dim fichierSauv As New StreamWriter("monFichier.txt", True)
        fichierSauv.WriteLine(nom)
        fichierSauv.WriteLine(highScore)
        fichierSauv.WriteLine(nbParties)
        fichierSauv.WriteLine(tempsJoué)
        fichierSauv.Close()
    End Sub

    Public Function getNumJoueur() As String
        Return numJoueur
    End Function

    Public Function getHighScore() As Integer
        Dim fichierSauv As New StreamReader("monFichier.txt")
        Dim HS As Integer
        For i As Integer = 0 To getNumJoueur()
            fichierSauv.ReadLine()
            If i = getNumJoueur() Then
                HS = fichierSauv.ReadLine()
                Exit For
            Else
                fichierSauv.ReadLine()
            End If
            fichierSauv.ReadLine()
            fichierSauv.ReadLine()
        Next
        fichierSauv.Close()
        Return HS
    End Function

    Public Sub setHighScore()
        Dim filePath As String = "monFichier.txt"
        Dim lines As List(Of String) = File.ReadLines(filePath).ToList()
        If getHighScore() > Jeu.getTempsPartie Then
            lines(((getNumJoueur() - 1) * 4) + 1) = Jeu.getTempsPartie
        End If
        File.WriteAllLines(filePath, lines)
    End Sub

    Public Function getNbParties() As Integer
        Dim fichierSauv As New StreamReader("monFichier.txt")
        Dim NP As Integer
        For i As Integer = 0 To getNumJoueur()
            fichierSauv.ReadLine()
            fichierSauv.ReadLine()
            If i = getNumJoueur() Then
                NP = fichierSauv.ReadLine()
                Exit For
            Else
                fichierSauv.ReadLine()
            End If
            fichierSauv.ReadLine()
        Next
        fichierSauv.Close()
        Return NP
    End Function

    Public Function incNbParties() As Integer
        Dim INP As Integer
        INP = getNbParties() + 1
        Return INP
    End Function

    Public Sub augNbParties()
        Dim filePath As String = "monFichier.txt"
        Dim lines As List(Of String) = File.ReadLines(filePath).ToList()
        lines(((getNumJoueur() - 1) * 4) + 2) = incNbParties()
        File.WriteAllLines(filePath, lines)
    End Sub

    Public Function getTempsJoué() As Integer
        Dim fichierSauv As New StreamReader("monFichier.txt")
        Dim TJ As Integer
        For i As Integer = 0 To getNumJoueur()
            fichierSauv.ReadLine()
            fichierSauv.ReadLine()
            fichierSauv.ReadLine()
            If i = getNumJoueur() Then
                TJ = fichierSauv.ReadLine()
                Exit For
            Else
                fichierSauv.ReadLine()
            End If
        Next
        fichierSauv.Close()
        Return TJ
    End Function

    Public Function incTempsJoué() As Integer
        Dim ITJ As Integer
        ITJ = getTempsJoué() + Jeu.getTempsPartie
        Return ITJ
    End Function

    Public Sub augTempsJoué()
        Dim filePath As String = "monFichier.txt"
        Dim lines As List(Of String) = File.ReadLines(filePath).ToList()
        lines(((getNumJoueur() - 1) * 4) + 3) = incTempsJoué()
        File.WriteAllLines(filePath, lines)
    End Sub
End Module
