#include <stdio.h>
#include "skeleton_arrayList.hpp"
//#include "skeleton_linkedList.hpp"


int main()
{
    FILE* file = fopen("in.txt", "r");
    if(file == NULL){
        return 1;
    }

   arrayList list;
    //linkedList list;
    init(&list);

    int func, param, param2;
    while(fscanf(file, "%d", &func) == 1 && func != 0)
    {
        if(func == 1 && fscanf(file, "%d", &param) == 1){
            printf("Insert %d\n", param);
            insert_cur(param, &list);
            print(&list);
            cout<<endl;
        }
        else if(func == 2){
            printf("Delete current item\n");
            int ret = delete_cur(&list);
            if(ret>=0){
                print(&list);
                printf("%d is deleted\n", ret);
            }
            else
                printf("List is empty\n");

            cout<<endl;    
        }
        else if(func == 3 && fscanf(file, "%d", &param) == 1){
            printf("Append %d\n", param);
            append(param, &list);
            print(&list);
            cout<<endl;
        }
        else if(func == 4){
            int ret = size(&list);
            printf("Size of the list is %d\n", ret);
            cout<<endl;
        }
        else if(func == 5 && fscanf(file, "%d", &param) == 1){
            printf("Prev %d\n", param);
            prev(param, &list);
            print(&list);
            cout<<endl;
            
        }
        else if(func == 6 && fscanf(file, "%d", &param) == 1){
            printf("Next %d\n", param);
            next(param, &list);
            print(&list);
            cout<<endl;
        }
        else if(func == 7 && fscanf(file, "%d", &param) == 1){
            int ret = is_present(param, &list);
            if(ret){
                printf("%d is present\n", param);
            }
            else{
                printf("%d is not present\n", param);
            }
            cout<<endl;
        }
        else if(func==8 ){
            printf("clear list\n");
            clear(&list);
            print(&list);
            cout<<endl;
        }
        else if(func==9 && fscanf(file,"%d",&param)==1){
            printf("delete %d\n",param);
            int ans=delete_item(param,&list);
            if(ans==-1) cout<<param<<" not found\n";
            else
            print(&list);
            cout<<endl;
        }
        else if(func==10 && fscanf(file,"%d %d",&param,&param2)==2){
            printf("swap index %d and %d\n",param,param2);
            swap_ind(param,param2,&list);
            print(&list);
            cout<<endl;
        }
        else if(func==11 && fscanf(file,"%d",&param)==1){
            printf("search %d\n",param);
            int ans=search(param,&list);
            if(ans==-1) printf("%d is not found\n",param);
            else{
                print(&list);
                printf("%d is found at %d\n",param,ans);
            }
                cout<<endl;
        }
        else if(func==12 && fscanf(file,"%d",&param)==1){
            printf("find %d\n",param);
            int ans=find(param,&list);
            if(ans==-1) printf("%d is not a valid index\n",param);
            else{
                print(&list);
                printf("%d is found at %d\n",ans,param);
            }
            cout<<endl;
        }
        else if(func==13 && fscanf(file,"%d %d",&param,&param2)==2){
            printf("update element at %d\n",param);
            int ans=update(param,param2,&list);
            if(ans==-1) printf("%d is not a valid index\n",param);
            else{
                print(&list);
                printf("%d is updated by %d\n",ans,param2);
            }
                cout<<endl;
        }
        else if(func==14){
            printf("trim\n");
            int ans=trim(&list);
            print(&list);
            printf("%d is removed\n",ans);
            cout<<endl;
        }
        else if(func==15){
            printf("reverse\n");
            reverse(&list);
            print(&list);
                cout<<endl;

        }
        // implement the remaining functionality here

    }
    cout<<"end"<<endl;
    free_list(&list);

    return 0;
}