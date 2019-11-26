Imports System.ComponentModel

Public Class Partie
    Dim tempsRestant As Integer = Jeu.getTemps()
    Dim retournementPossible As Boolean = False
    Dim ensembleCartesTrouvées() As Boolean = {False, False, False, False, False}
    Dim AvantderniereCarteRelevée As Integer = 6
    Dim nbCartesRetournées As Integer = 0


    Private Sub Partie_Closing(sender As Object, e As CancelEventArgs) Handles Me.Closing
        ACCEUIL.Show()
    End Sub

    Private Sub BtnAbandon_Click(sender As Object, e As EventArgs) Handles BtnAbandon.Click
        Close()
    End Sub

    Private Sub Partie_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        LabelMinuterie.Text = Jeu.getTemps() & " secondes"
        MélangerCartes()
    End Sub

    Private Sub MélangerCartes()
        Dim tabCartes(20) As Integer
        For i As Integer = 0 To UBound(tabCartes)
            tabCartes(i) = i Mod 5
        Next
        Dim random As New Random()
        Dim aleatoire As Integer
        For i As Integer = 0 To UBound(tabCartes) * 2
            Dim transition As Integer
            aleatoire = random.Next(0, UBound(tabCartes))
            transition = tabCartes(i Mod UBound(tabCartes))
            tabCartes(i Mod UBound(tabCartes)) = tabCartes(aleatoire)
            tabCartes(aleatoire) = transition
        Next

        Dim j As Integer = 0
        For Each lab As Label In PanelCartes.Controls
            lab.Tag = tabCartes(j)
            lab.Text = tabCartes(j)
            j += 1
        Next
    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        tempsRestant -= 1
        LabelMinuterie.Text = tempsRestant
        LabelMinuterie.Text &= " seconde"
        If (tempsRestant > 1) Then
            LabelMinuterie.Text &= "s"
        ElseIf (tempsRestant = 0) Then
            estPerdue()
        End If
    End Sub

    Private Sub LabelCartes_Click(sender As Object, e As EventArgs) Handles Label1.Click, Label2.Click, Label3.Click, Label4.Click, Label5.Click, Label6.Click, Label7.Click, Label8.Click,
        Label9.Click, Label10.Click, Label11.Click, Label12.Click, Label13.Click, Label14.Click, Label15.Click, Label16.Click, Label17.Click, Label18.Click, Label19.Click, Label20.Click
        TimerRetournement.Stop()
        afficherCarte(sender)
        sender.tag
        If (AvantderniereCarteRelevée <> 6) And (AvantderniereCarteRelevée <> sender.tag) Then
            Me.Refresh()
            Threading.Thread.Sleep(1000)
            retournerCartes(AvantderniereCarteRelevée, sender.tag)
            AvantderniereCarteRelevée = 6
            nbCartesRetournées = 0
        Else
            AvantderniereCarteRelevée = sender.tag
            nbCartesRetournées += 1
        End If
        If (nbCartesRetournées = 4) Then
            For Each lab As Label In PanelCartes.Controls
                If (lab.Tag = sender.tag) Then
                    lab.Enabled = False
                    ensembleCartesTrouvées(AvantderniereCarteRelevée) = True
                End If
            Next
            nbCartesRetournées = 0
            AvantderniereCarteRelevée = 6
        End If

        estGagnée()
    End Sub

    Private Sub afficherCarte(lab As Label)
        Select Case lab.Tag
            Case "0"
                lab.Image = My.Resources._0
            Case "1"
                lab.Image = My.Resources._1
            Case "2"
                lab.Image = My.Resources._2
            Case "3"
                lab.Image = My.Resources._3
            Case "4"
                lab.Image = My.Resources._4
        End Select
    End Sub
    Private Sub retournerCartes(num1 As Integer, num2 As Integer)
        For Each lab As Label In PanelCartes.Controls
            If lab.Tag = num1 Or lab.Tag = num2 Then
                lab.Image = My.Resources.Back
            End If
        Next
    End Sub

    Private Sub ButtonPause_Click(sender As Object, e As EventArgs) Handles ButtonPause.Click
        Timer1.Enabled = Not Timer1.Enabled
        PanelCartes.Enabled = Not PanelCartes.Enabled
    End Sub

    Private Sub ButtonMélanger_Click(sender As Object, e As EventArgs) Handles ButtonMélanger.Click
        MélangerCartes()
        For Each lab As Label In PanelCartes.Controls
            If ensembleCartesTrouvées(lab.Tag) = True Then
                lab.Enabled = False
                afficherCarte(lab)
            Else
                lab.Enabled = True
                lab.Image = My.Resources.Back
            End If
        Next
    End Sub


    Sub estGagnée()
        Dim b As Boolean = True
        For Each bool As Boolean In ensembleCartesTrouvées
            If bool = False Then
                b = False
            End If
        Next
        If b = True Then
            setTempsPartie(getTemps() - tempsRestant)
            Timer1.Stop()
            setHighScore()
            augTempsJoué()
            Me.Enabled = False
            MsgBox("La partie est terminée " & LabelNom.Text & ", vous avez gagné", MsgBoxStyle.OkOnly)
            Me.Close()
        End If
    End Sub

    Sub estPerdue()
        setTempsPartie(getTemps())
        Timer1.Stop()
        augTempsJoué()
        Me.Enabled = False
        MsgBox("La partie est terminée " & LabelNom.Text & ", vous avez perdu", MsgBoxStyle.OkOnly)
        Me.Close()
    End Sub

    Public Function getTempsRestant()
        Return tempsRestant
    End Function
End Class

