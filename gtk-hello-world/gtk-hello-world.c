#include <gtk/gtk.h>

static void on_activate(GtkApplication *app, gpointer user_data) {
    // CREATE WINDOW
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "GTK Hello World");
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 320);

    // CREATE HELLO WORLD LABEL
    GtkWidget *label = gtk_label_new("Hello World!");

    // ADD LABEL TO WINDOW
    gtk_container_add(GTK_CONTAINER(window), label);

    // SHOW WIDGETS
    gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new("com.ssaxel03.gtkhelloworld", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}