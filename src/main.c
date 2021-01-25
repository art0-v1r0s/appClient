#include <gtk/gtk.h>

typedef struct {
    GtkWidget *entry_id_connexion;
    GtkWidget *entry_pass_connexion;
    GtkWidget *entry_id_inscription;
    GtkWidget *entry_pass_inscription;
    GtkWidget *rb_famille;
    GtkWidget *rb_etudiant;
    
} app_widgets;



int main(int argc, char *argv[])
{
    GtkBuilder      *builder;
    GtkWidget       *window;
    //instantiate structure , allocate memory;
    app_widgets     *widgets = g_slice_new(app_widgets);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    //get pointer to entry widgets ->entry connexion
    widgets->entry_id_connexion = GTK_WIDGET(gtk_builder_get_object(builder, "entry_id_connexion"));
    widgets->entry_pass_connexion = GTK_WIDGET(gtk_builder_get_object(builder, "entry_pass_connexion"));

    //get pointer to entry widgets ->entry inscription
    widgets->entry_id_inscription = GTK_WIDGET(gtk_builder_get_object(builder, "entry_id_inscription"));
    widgets->entry_pass_inscription = GTK_WIDGET(gtk_builder_get_object(builder, "entry_pass_inscription"));
    widgets->rb_etudiant = GTK_WIDGET(gtk_builder_get_object(builder, "rb_etudiant"));
    widgets->rb_famille = GTK_WIDGET(gtk_builder_get_object(builder, "rb_famille"));


    gtk_builder_connect_signals(builder, widgets);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    g_slice_free(app_widgets, widgets);

    return 0;
}
void home(GtkButton * button,GtkStack * stack){
    gtk_stack_set_visible_child_name (stack,"page1");
}

void inscription(GtkButton * button,GtkStack * stack){

    //printf("ta cliqué bonhomme\n");
    //printf(gtk_stack_get_visible_child_name (stack));
    gtk_stack_set_visible_child_name (stack,"page2");
    
    
}
void connexion(GtkButton * button,GtkStack * stack){

    gtk_stack_set_visible_child_name (stack,"page3");
}

void submitCo(GtkButton * button,app_widgets * entryCo){


    printf("vous avez id: %s\n",gtk_entry_get_text (GTK_ENTRY(entryCo->entry_id_connexion)));
    printf("vous avez pass: %s\n",gtk_entry_get_text (GTK_ENTRY(entryCo->entry_pass_connexion)));


}
void submitIns(GtkButton * button,app_widgets * entryIns){



 if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(entryIns->rb_etudiant)))
 {
        printf("vous etes un compte etudiant\n");
 }

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(entryIns->rb_famille)))
{
        printf("vous etes un compte famille\n");
}

    printf("vous avez id: %s\n",gtk_entry_get_text (GTK_ENTRY(entryIns->entry_id_inscription)));

//condition texte sup 5

if (gtk_entry_get_text_length (GTK_ENTRY(entryIns->entry_pass_inscription))>5)
{
        printf("vous avez pass: %s\n",gtk_entry_get_text (GTK_ENTRY(entryIns->entry_pass_inscription)));
}else
    printf("votre mot de passe est inférieur a 5\n");


}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}

