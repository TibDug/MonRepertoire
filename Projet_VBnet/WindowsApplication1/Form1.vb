Public Class ACCEUIL
    Private Sub ComboBoxNom_TextChanged(sender As Object, e As EventArgs) Handles ComboBoxNom.TextChanged
        If Len(ComboBoxNom.Text) <> 0 Then
            BtnJouer.Enabled = True
        Else
            BtnJouer.Enabled = False
        End If
    End Sub

    Private Sub BtnQuitter_Click(sender As Object, e As EventArgs) Handles BtnQuitter.Click
        If MsgBox("Voulez vous vraiment quitter l'application?", MsgBoxStyle.YesNo) = MsgBoxResult.Yes Then
            Me.Close()
        End If
    End Sub

    Private Sub BtnOptions_Click(sender As Object, e As EventArgs) Handles BtnOptions.Click
        Options.Show()
    End Sub

    Private Sub BtnJouer_Click(sender As Object, e As EventArgs) Handles BtnJouer.Click
        ComboBoxNom.Text = UCase(LTrim(RTrim(ComboBoxNom.Text)))
        Me.Hide()
        Partie.Show()
        newJoueur(ComboBoxNom.Text)
        Partie.LabelNom.Text = ComboBoxNom.Text
        augNbParties()
    End Sub

End Class
