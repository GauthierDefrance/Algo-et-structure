/* app.c - Exemple GTK3 : fenêtre, label et bouton */
#include <gtk/gtk.h>

static void
on_button_clicked(GtkButton *button, gpointer user_data)
{
    GtkLabel *label = GTK_LABEL(user_data);
    static int count = 0;
    count++;
    char buf[64];
    g_snprintf(buf, sizeof(buf), "Boutons cliqués : %d", count);
    gtk_label_set_text(label, buf);
}

int
main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Exemple GTK3");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 180);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *label = gtk_label_new("Bonjour GTK !");
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Clique-moi");
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), label);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
