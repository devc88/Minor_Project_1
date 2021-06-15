 #include <gtk/gtk.h>
    #include <string.h>

    char arr[50],arr2[50];
    int state_of_rad1=0,state_of_rad2=0;
    int musicselected,textselected;


    int musicss(){
    return musicselected;
    }

    int textss(){
    return textselected;
    }

    void combo_changed (GtkWidget *wid, gpointer ptr)
    {
    int sel = gtk_combo_box_get_active (GTK_COMBO_BOX (wid));
    char *selected = gtk_combo_box_text_get_active_text (
    GTK_COMBO_BOX_TEXT (wid));
    printf ("The value of the combo is %d %s\n", sel, selected);
    musicselected=sel;

   }

    void combo_changed2 (GtkWidget *wid, gpointer ptr)
    {
    int sel = gtk_combo_box_get_active (GTK_COMBO_BOX (wid));
    char *selected = gtk_combo_box_text_get_active_text (
    GTK_COMBO_BOX_TEXT (wid));
    printf ("The value of the combo is %d %s\n", sel, selected);
    textselected=sel;

   }



    static void open_dialog(GtkWidget* button, gpointer window)
    {
        GtkWidget *dialog;
        dialog = gtk_file_chooser_dialog_new("Choose a file", GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_OK, GTK_RESPONSE_OK, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);
        gtk_widget_show_all(dialog);
        gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), g_get_home_dir());
        gint resp = gtk_dialog_run(GTK_DIALOG(dialog));



        if(resp == GTK_RESPONSE_OK){
            strcpy(arr,gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
            strcpy(arr2,gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(dialog)));
            //g_print("%s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
            //g_print("%s\n", gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(dialog)));
        }
        else
            g_print("You pressed Cancel\n");
        gtk_widget_destroy(dialog);


    }


char *intilizeitall(int argc, char* argv[]){


        gtk_init(&argc, &argv);
        GtkWidget *window, *button,*label,*label2,*labe22;
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);



        /*
        gchar *str = "<b>ZetCode</b>, knowledge only matters";
        label = gtk_label_new(NULL);
        gtk_label_set_markup(GTK_LABEL(label), str);
        gtk_container_add(GTK_CONTAINER(window), label);
        gtk_widget_show(label);
        */

        gchar *str = "<b >FILE CATEGORIZATION </b>";
        label = gtk_label_new(NULL);
        gtk_label_set_markup(GTK_LABEL(label), str);

        gchar *str2 = "<b >Select Type of categorization for music</b>";
        label2 = gtk_label_new(NULL);
        gtk_label_set_markup(GTK_LABEL(label2), str2);

        gchar *str22 = "<b >Do you want to categorize Coding files</b>";
        labe22 = gtk_label_new(NULL);
        gtk_label_set_markup(GTK_LABEL(labe22), str22);


        button = gtk_button_new_with_label("Click me");
        g_signal_connect(button, "clicked", G_CALLBACK(open_dialog), window);


        GdkColor color;
        gdk_color_parse ("pink", &color);
        gtk_widget_modify_bg (GTK_WIDGET(label), GTK_STATE_NORMAL, &color);



        //g_signal_connect (artist, "toggled", G_CALLBACK (check_toggle),NULL);

        GtkWidget *comb = gtk_combo_box_text_new ();
        gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (comb),"ARTIST");
        gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (comb),"ALBUM");
        gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (comb),"YEAR");

        gtk_combo_box_set_active (GTK_COMBO_BOX (comb), -1);
        g_signal_connect (comb, "changed", G_CALLBACK (combo_changed),NULL);


        // ---------------------------------------------------------------------

        GtkWidget *comb2 = gtk_combo_box_text_new ();
        gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (comb2),"NO");
        gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (comb2),"YES");

        gtk_combo_box_set_active (GTK_COMBO_BOX (comb2), -1);
        g_signal_connect (comb2, "changed", G_CALLBACK (combo_changed2),NULL);

        // ---------------------------------------------------------------------


        gtk_widget_modify_bg (GTK_WIDGET(comb2), GTK_STATE_NORMAL, &color);

        GtkWidget *box = gtk_vbox_new (FALSE, 10);
        gtk_box_pack_start (GTK_BOX (box), label, TRUE, TRUE, 20);
        gtk_box_pack_start (GTK_BOX (box), button, TRUE, TRUE, 4);
        gtk_box_pack_start (GTK_BOX (box), label2, TRUE, TRUE, 3);
        gtk_box_pack_start (GTK_BOX (box), comb, TRUE, TRUE, 4);
        gtk_box_pack_start (GTK_BOX (box), labe22, TRUE, TRUE, 3);
        gtk_box_pack_start (GTK_BOX (box), comb2, TRUE, TRUE, 4);

         gtk_widget_modify_bg (GTK_WIDGET(comb2), GTK_STATE_NORMAL, &color);

        gtk_container_set_border_width(GTK_CONTAINER(window), 100);


        gtk_container_add (GTK_CONTAINER (window), box);


        gtk_widget_show_all(window);
        gtk_main();

//        printf("the state1  %d\n the state2 %d\n",state1,state2);

        return arr2;
    }

  char *intilizeitall2(int argc, char* argv[]){

        gtk_init(&argc, &argv);
        GtkWidget *window, *button,*label;
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
   
        button = gtk_button_new_with_label("Click me");
        g_signal_connect(button, "clicked", G_CALLBACK(open_dialog), window);
        gtk_container_set_border_width(GTK_CONTAINER(window), 200);
        gtk_container_add(GTK_CONTAINER(window), button);




        gtk_widget_show_all(window);
        gtk_main();

        return arr;
    }



