Public Class Options
    Private Sub Options_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        TextBoxTemps.Text = Jeu.getTemps()
    End Sub

    Private Sub BtnAbandon_Click(sender As Object, e As EventArgs) Handles BtnAbandon.Click
        Me.Hide()
    End Sub

    Private Sub BtnValider_Click(sender As Object, e As EventArgs) Handles BtnValider.Click
        Jeu.setTemps(TextBoxTemps.Text)
        Me.Hide()
    End Sub

    Private Sub TextBoxTemps_KeyPress(sender As Object, e As KeyPressEventArgs) Handles TextBoxTemps.KeyPress
        If (Not (IsNumeric(e.KeyChar)) And Not (e.KeyChar = vbBack)) Then
            e.Handled = True
        End If
    End Sub

    Private Sub BtnAide1_Click(sender As Object, e As EventArgs) Handles BtnAide1.Click
        MsgBox("Vous ne pouvez entrer que des chiffres, le temps est en secondes.", MsgBoxStyle.OkOnly)
    End Sub

    Private Sub ButtonAide2_Click(sender As Object, e As EventArgs)
        MsgBox("Si vous décochez cette case, vous pourrez jouer sans limite de temps.", MsgBoxStyle.OkOnly)
    End Sub
End Class