#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Amirmahdi Tahmasebi 402106178


struct new {char name[100]; int credit; int capacity; int department; char pre[100]; struct new* next; char status; int masterId;};
struct new* newCourses;
struct daneshKade {int code; struct daneshKade* next;};
struct daneshKade* daneshKadeHa;
struct daneshJo { char firstname[100]; char lastname[100]; int id; int dp_code; struct daneshJo* next;};
struct daneshJo* daneshJoHa;
struct dars {char name[100]; int credit; double mark; int student_id; struct dars* next; };
struct dars* darsHa;
struct ostad { char firstname[100]; char lastname[100]; int id; struct ostad* next;};
struct ostad* ostadHa;
void addToEnd_daneshkadeHa(int a, struct daneshKade* d){
    while(d -> next != NULL)
        d= d-> next;
    d->code = a; d->next = (struct daneshKade*)calloc(1,sizeof(struct daneshKade)); d->next->next = NULL;
}
struct daneshKade* findBycode_daneshkadeHa(int a, struct daneshKade* d){
    while(d -> next != NULL){
        if(d->code == a)
            return d;
        d= d-> next;
    }
    return NULL;
}
void print_daneshkadeHa(struct daneshKade* d){
    while(d -> next != NULL){
        printf("code = %d\n", d->code);
        d= d-> next;
    }
}
struct daneshJo* findByid_daneshJoHa(int a, struct daneshJo* d){
    while(d -> next != NULL){
        if(d->id == a)
            return d;
        d= d-> next;
    }
    return NULL;
}
void addToEnd_daneshJo(int id, char* firstname, char* lastname, int dp_code, struct daneshJo* d){
    while(d -> next != NULL)
        d= d-> next;
    d->id = id;
    d->dp_code = dp_code;
    strcpy(d->firstname, firstname);
    strcpy(d->lastname, lastname);
    d->next = (struct daneshJo*)calloc(1,sizeof(struct daneshJo));
    d->next->next = NULL;
}
void print_daneshJoHa(struct daneshJo* d){
    while(d -> next != NULL){
        printf("id = %d, first name = %s, lastname = %s, dp = %d\n", d->id, d->firstname, d->lastname, d->dp_code);
        d= d-> next;
    }
}
void addToEnd_dars(int id, char* name, int credit, double mark, struct dars* d){
    while(d -> next != NULL)
        d= d-> next;
    d->student_id = id;
    d->credit = credit;
    strcpy(d->name, name);
    d->mark = mark;
    d->next = (struct dars*)calloc(1,sizeof(struct dars));
    d->next->next = NULL;
}
void print_dars(struct dars* d){
    while(d -> next != NULL){
        printf("stdid = %d, name = %s, mark = %lf, credit = %d\n", d->student_id, d->name, d->mark, d->credit);
        d= d-> next;
    }
}
struct ostad* findByid_ostad(int a, struct ostad* d){
    while(d -> next != NULL){
        if(d->id == a)
            return d;
        d= d-> next;
    }
    return NULL;
}
struct ostad* findName_ostad(char first[100], char last[100]){
    struct ostad* d = ostadHa;
    while(d -> next != NULL){
        if(!strcmp(d->firstname, first) && !strcmp(d->lastname, last))
            return d;
        d= d-> next;
    }
    return NULL;
}
void addToEnd_ostad(int id, char* firstname, char* lastname, struct ostad* d){
    while(d -> next != NULL)
        d= d-> next;
    d->id = id;
    strcpy(d->firstname, firstname);
    strcpy(d->lastname, lastname);
    d->next = (struct ostad*)calloc(1,sizeof(struct ostad));
    d->next->next = NULL;
}
void addToEnd_new(struct new* d, char name[100], int credit, int capacity, int department, char pre[100], int masterId){
    while(d -> next != NULL){
        if(!strcmp(d->name, name) && d->status == 0){
            d->status = 1;
            return;
        }
        d= d-> next;
    }
    d->credit = credit;
    d->capacity = capacity;
    d->department = department;
    strcpy(d->pre, pre);
    d->masterId = masterId;
    d->status = 1;
    strcpy(d->name, name);
    d->next = (struct new*)calloc(1,sizeof(struct new));
    d->next->next = NULL;
}
void print_ostad(struct ostad* d){
    while(d -> next != NULL){
        printf("id = %d, first name = %s, lastname = %s\n", d->id, d->firstname, d->lastname);
        d= d-> next;
    }
}
char check_input(char* a, char*b){
    if(strstr(a, b) == a &&(a[strlen(b)] == ' ' || a[strlen(b)] == 0))
        return 1;
    return 0;
}
double calculate_gpa(int student_id, struct dars* d){
    double sum = 0; int count = 0;
    while(d -> next != NULL){
        if(d->student_id == student_id){
            sum += d->mark * d->credit;
            count += d->credit;
        }
        d= d-> next;
    }
    return sum / count;
}
struct _5top{
    char firstname[100];
    char lastname[100];
    double gpa;
};
struct BARDASHTEH { char name[100]; int dp; int masterId; int stdid; struct BARDASHTEH* next; int status; int credit;};
struct BARDASHTEH* bardashteHa;
void addToEnd_BardashteHa(int creadit, int masterId, int dp, int stdid, char name[100]){
    struct BARDASHTEH* d = bardashteHa;
    while(d->next != NULL)
        d = d->next;
    d->credit = creadit;
    d->dp = dp;
    d->masterId = masterId;
    d->status = 1;
    d->stdid = stdid;
    strcpy(d->name, name);
    d->next = (struct BARDASHTEH*)calloc(1, sizeof(struct BARDASHTEH));
    d->next->next = NULL;
}
int getCapacity(char name[100], int MasterId){
    struct new* d = newCourses;
    int count = 0;
    while(d->next != NULL){
        if(!strcmp(d->name, name) && d->masterId == MasterId && d->status == 1){
            count = d->capacity;
            break;
        }
        d = d->next;
    }
    if(count == 0)
        return -1000;
    struct BARDASHTEH* c = bardashteHa;
    while(c->next != NULL){
        if(!strcmp(c->name, name) && c->masterId == MasterId && c->status == 1)
            count -= 1;
        c = c->next;
    }
    return count;
}

void show_courses_d(int dp){
    struct new * d = newCourses;
    while(d->next != NULL){
        if(d->department == dp && d->status == 1)
            printf("%s %s %d\n", d->name, findByid_ostad(d->masterId, ostadHa)->lastname, getCapacity(d->name, d->masterId));
        d = d->next;
    }
}

int main() {
    int log_student = -1;
    int log_ostad = -1;
    int log_daneshkade = -1;
    bardashteHa = (struct BARDASHTEH*)calloc(1, sizeof(struct BARDASHTEH));
    char* command = (char*)(calloc(3000, sizeof(char)));
    daneshKadeHa = (struct daneshKade*)calloc(1,sizeof(struct daneshKade));
    daneshJoHa = (struct daneshJo*)calloc(1,sizeof(struct daneshJo));
    darsHa = (struct dars*)calloc(1,sizeof(struct dars));
    ostadHa = (struct ostad*)calloc(1,sizeof(struct ostad));
    newCourses = (struct new*)calloc(1,sizeof(struct new));
    while(1){
        command[0] = 0;
        scanf("%[^\n]s", command);
        getchar();
        if(check_input(command, "register-d")){
            int code = 0;
            if(strlen(command) == 10 || strlen(command) == 11){printf("Invalid inputs!\n"); continue;}
            sscanf(command, "register-d %d", &code);
            if(code <= 0){ printf("Invalid inputs!\n"); continue;}
            if(findBycode_daneshkadeHa(code, daneshKadeHa)){printf("The department account already exists!\n"); continue;}
            addToEnd_daneshkadeHa(code, daneshKadeHa);
            printf("The department added successfully\n");
            continue;
        }
        else if(check_input(command, "register-s")){
            char* firstname = (char*)calloc(100, sizeof(char));
            char* lastname = (char*)calloc(100, sizeof(char));
            int id = 0;
            int dp_code = -1234591;
            sscanf(command, "register-s %s %s %d %d", firstname, lastname, &id, &dp_code);
            if(firstname[0] == 0 || lastname[0] == 0 || id == 0 || dp_code == -1234591){printf("Invalid inputs!\n"); continue;}
            if(dp_code <= 0){printf("Invalid department code!\n"); continue;}
            struct daneshKade* r = daneshKadeHa;
            int flag = 0;
            while(r->next != NULL){
                if(r->code == dp_code) flag = 1;
                r = r->next;
            }
            if(!flag){printf("Invalid department code!\n"); continue;}
            addToEnd_daneshJo(id, firstname, lastname, dp_code, daneshJoHa);
            while(1){
                command[0] = 0;
                scanf("%[^\n]s", command);
                getchar();
                int credit = 0;
                double mark = 0;
                char name[100];
                sscanf(command, "%s %lf %d", name, &mark, &credit);
                if(check_input(command, "end"))
                    break;
                addToEnd_dars(id, name, credit, mark, darsHa);
            }
            printf("Registered successfully!\n");
            continue;
        }
        else if(check_input(command, "register-m")){
            char firstname[100];
            firstname[0] = 0;
            char lastname[100];
            lastname[0] = 0;
            int id = -1;
            sscanf(command, "register-m %s %s %d", firstname, lastname, &id);
            if(id <= -1 || firstname[0] == 0 || lastname[0] == 0){ printf("Invalid inputs!\n"); continue;}
            addToEnd_ostad(id, firstname, lastname, ostadHa);
            printf("Registered successfully\n");
            continue;
        }
        else if(check_input(command, "login-s")){
            char firstname[100];
            firstname[0] = 0;
            char lastname[100];
            lastname[0] = 0;
            int id = -1;
            sscanf(command, "login-s %s %s %d", firstname, lastname, &id);
            if(log_student != -1 || log_daneshkade != -1 || log_ostad != -1){printf("You can't login without logging out of prev account!\n"); continue;}
            if(id <= -1 || firstname[0] == 0 || lastname[0] == 0){ printf("Invalid inputs!\n"); continue;}
            struct daneshJo* d = daneshJoHa;
            char flag = 0;
            while(d -> next != NULL){
                if(!strcmp(d->firstname, firstname) && !strcmp(d->lastname, lastname)){
                    if(d->id == id){
                        log_student = id;
                        printf("You're logged in as a student!\n");
                    }
                    else{
                        printf("Wrong id!\n");
                    }
                    flag = 1;
                    break;
                }
                d= d-> next;
            }
            if(flag)
                continue;
            printf("No student exists with given information!\n");
            continue;
        }
        else if(check_input(command, "show-gpa")){
            if(log_ostad == -1 && log_daneshkade == -1 && log_student != -1){
                struct dars* d = darsHa;
                double sum = 0; int count = 0;
                while(d -> next != NULL){
                    if(d->student_id == log_student){
                        sum += d->mark * d->credit;
                        count += d->credit;
                    }
                    d= d-> next;
                }
                printf("GPA: %.2lf\n", sum / count);
            }
            else{
                printf("You should login as a student to calculate gpa!\n");
            }
            continue;
        }
        else if(check_input(command, "show-passed-courses")){
            if(log_ostad == -1 && log_daneshkade == -1 && log_student != -1){
                struct dars* d = darsHa;
                int i = 1;
                while(d -> next != NULL){
                    if(d->student_id == log_student){
                        printf("%d Course: %s , Grade: %.2lf\n", i, d->name, d->mark);
                        i++;
                    }
                    d= d-> next;
                }
            }
            else{
                printf("You should login as a student to show passed courses!\n");
            }
            continue;
        }
        else if(check_input(command, "show-total-credits")){
            if(log_ostad == -1 && log_daneshkade == -1 && log_student != -1){
                struct dars* d = darsHa;
                int count = 0;
                while(d -> next != NULL){
                    if(d->student_id == log_student){
                        count += d->credit;
                    }
                    d= d-> next;
                }
                printf("Credits: %d\n", count);
            }
            else{
                printf("You should login as a student to show number of credits!\n");
            }
            continue;
        }
        else if(check_input(command, "login-m")){
            char firstname[100];
            firstname[0] = 0;
            char lastname[100];
            lastname[0] = 0;
            int id = -1;
            sscanf(command, "login-m %s %s %d", firstname, lastname, &id);
            if(log_student != -1 || log_daneshkade != -1 || log_ostad != -1){printf("You can't login without logging out of prev account!\n"); continue;}
            if(id <= -1 || firstname[0] == 0 || lastname[0] == 0){ printf("Invalid inputs!\n"); continue;}
            struct ostad* d = ostadHa;
            char flag = 0;
            while(d -> next != NULL){
                if(!strcmp(d->firstname, firstname) && !strcmp(d->lastname, lastname)){
                    if(d->id == id){
                        log_ostad= id;
                        printf("You're logged in as a master!\n");
                    }
                    else{
                        printf("Wrong id!\n");
                    }
                    flag = 1;
                    break;
                }
                d= d-> next;
            }
            if(flag)
                continue;
            printf("No master exists with given information!\n");
            continue;
        }
        else if(check_input(command, "login-d")){
            int id = -1234591;
            sscanf(command, "login-d %d", &id);
            if(log_student != -1 || log_daneshkade != -1 || log_ostad != -1){printf("You can't login without logging out of prev account!\n"); continue;}
            struct daneshKade* d = daneshKadeHa;
            char flag = 1;
            while(d -> next != NULL){
                if(d->code == id){
                    flag = 0;
                    break;
                }
                d= d-> next;
            }
            if(flag){
                printf("No department exists with given information!\n");
                continue;
            }
            log_daneshkade = id;
            printf("You're logged in as a department!\n");
            continue;
        }
        else if(check_input(command, "show-top-5")){
            if(log_ostad == -1 && log_daneshkade != -1 && log_student == -1){
                struct _5top* list = (struct _5top*)calloc(5, sizeof(struct _5top));
                struct daneshJo* d = daneshJoHa;
                while(d -> next != NULL){
                    if(d->dp_code == log_daneshkade){
                        double average = calculate_gpa(d->id, darsHa);
                        for(int i = 0; i < 5; i++){
                            if(average > list[i].gpa){
                                for(int j = 4; j > i; j--){
                                    list[j] = list[j-1];
                                }
                                strcpy(list[i].firstname, d->firstname);
                                strcpy(list[i].lastname, d->lastname);
                                list[i].gpa = average;
                                break;
                            }
                        }
                    }
                    d= d-> next;
                }
                for(int i = 0; i < 5; i++){
                    if(list[i].firstname[0] != 0){
                        printf("%s %s %.2lf\n", list[i].firstname, list[i].lastname, list[i].gpa);
                    }
                }
            }
            else{
                printf("Only a department account can access top 5 scores!\n");
            }
            continue;
        }
        else if(check_input(command, "logout")){
            log_daneshkade = log_ostad = log_student = -1;
            printf("You're logged out!\n");
            continue;
        }
        else if(check_input(command, "exit")){
            break;
        }
        else if(check_input(command, "create-course")){
            if(log_ostad != -1 && log_daneshkade == -1 && log_student == -1){
                int credit = -123453;
                char name[100];
                name[0] = 0;
                int capacity = -123453;
                int dp = - 123453;
                char pre[100]; pre[0] = 0;
                sscanf(command, "create-course %s %d %d %d %s", name, &credit, &capacity, &dp, pre);
                if(name[0] == 0 || credit == -123453 || capacity == -123453 || dp == -123453){printf("Invalid inputs!\n"); continue;}
                addToEnd_new(newCourses, name, credit, capacity, dp, pre, log_ostad);
                printf("Course added successfully\n");
            }
            else{
                printf("You should login as a master to create course!\n");
            }
            continue;
        }
        else if(check_input(command, "delete_course")){
            if(log_ostad != -1){
                char name[100];
                name[0] = 0;
                sscanf(command, "delete_course %s", name);
                struct new* d = newCourses;
                int flag = 0;
                while(d->next != NULL){
                    if(d->masterId == log_ostad && !strcasecmp(d->name, name) && d->status == 1){
                        d->status = 0;
                        printf("Course deleted successfully!\n");
                        struct BARDASHTEH* c = bardashteHa;
                        while(c->next != NULL){
                            if(!strcmp(c->name, name) &&  log_ostad == c->masterId)
                                c->status = 0;
                            c = c->next;
                        }
                        flag = 1;
                        break;
                    }
                    d=d->next;
                }
                if(flag)
                    continue;
                printf("Course does not exist\n");
                continue;
            }
            else if(log_daneshkade != -1){
                char name[100];
                name[0] = 0;
                char first[100];
                first[0] = 0;
                char last[100];
                last[0] = 0;
                sscanf(command, "delete_course %s %s %s", name, first, last);
                struct new* d = newCourses;
                int flag = 0;
                while(d->next != NULL){
                    if(!strcasecmp(d->name, name)){
                        if(d->status && !strcmp(findByid_ostad(d->masterId, ostadHa)->firstname, first) && !strcmp(findByid_ostad(d->masterId, ostadHa)->lastname, last)){
                            if(d->department == log_daneshkade){
                                printf("Course deleted successfully!\n");
                                d->status = 0;
                                struct BARDASHTEH* c = bardashteHa;
                                while(c->next != NULL){
                                    if(!strcmp(c->name, name) &&  !strcmp(findByid_ostad(c->masterId, ostadHa)->firstname, first) &&  !strcmp(findByid_ostad(c->masterId, ostadHa)->lastname, last))
                                        c->status = 0;
                                    c = c->next;
                                }
                                flag = 1;
                                break;
                            }
                            else{
                                printf("You can't delete another department's course!\n");
                                flag = 1;
                                break;
                            }
                        }
                    }
                    d=d->next;
                }
                if(flag)
                    continue;
                printf("Course does not exist!\n");
                continue;
            }
            else{
                printf("You don't have access to delete this course!\n");
            }
            continue;
        }
        else if(check_input(command, "show-d-courses")){
            if(log_ostad == -1 && log_daneshkade != -1 && log_student == -1){
                show_courses_d(log_daneshkade);
            }
            else{
                printf("You should login as a departmnet to show depaertment courses!\n");
            }
            continue;
        }
        else if(check_input(command, "show-courses")){
            int id = -123452;
            sscanf(command, "show-courses %d", &id);
            if(id == -123452){
                printf("Invalid inputs!\n");
                continue;
            }
            int flag = 1;
            struct daneshKade* d = daneshKadeHa;
            while(d->next != NULL){
                if(d->code == id) flag = 0;
                d = d->next;
            }
            if(flag){
                printf("This department code is invalid!\n");
                continue;
            }
            show_courses_d(id);
            continue;
        }

        else if(check_input(command, "add-s")){
            if(log_student != -1){
                char name[100];
                name[0] = 0;
                char first[100];
                first[0] = 0;
                char last[100];
                last[0] = 0;
                sscanf(command, "add-s %s %s %s", name, first, last);
                if(name[0] == 0 || first[0] == 0 || last[0] == 0){
                    printf("Invalid inputs!\n");
                    continue;
                }
                if(findName_ostad(first, last) == NULL){
                    printf("No course exists with given name and master!\n");
                    continue;
                }
                int MasterId = (findName_ostad(first, last)->id);
                struct new* d = newCourses;
                int flag = 1;
                int error = 0;
                while(d->next != NULL){
                    if(!strcmp(d->name, name) && d->masterId == MasterId && d->status == 1){
                        flag = 0;
                        if(getCapacity(name, MasterId) <= 0){
                            printf("The capacity of course is full!\n");
                            error++;
                            break;
                        }
                        struct BARDASHTEH* c = bardashteHa;
                        int sum = 0;
                        while(c->next != NULL){
                            if(c->stdid == log_student && c->status == 1){
                                sum += c->credit;
                            }
                            c = c->next;
                        }
                        sum+= d->credit;
                        if(sum > 24){printf("You've reached the limit of taking courses!\n"); break; error++;}
                        struct dars* f = darsHa;
                        int r = 1;
                        while(f->next != NULL){
                            if(!strcmp(f->name, d->pre) && f->student_id == log_student){
                                r = 0;
                                break;
                            }
                            f = f->next;
                        }
                        if(r){
                            printf("You haven't passed preneeded courses yet!\n");
                            break;
                        }
                        c = bardashteHa;
                        while(c->next != NULL){
                            if(c->stdid == log_student && !strcmp(c->name, d->name) && c->status == 1){
                                printf("You already have this course!\n");
                                error++;
                                break;
                            }
                            c = c->next;
                        }
                        if(error) break;;
                        f = darsHa;
                        while(f->next != NULL){
                            if(!strcmp(f->name, name) && f->student_id == log_student){
                                printf("You already have this course!\n");
                                error++;
                                break;
                            }
                            f = f->next;
                        }
                        if(error) break;
                        addToEnd_BardashteHa(d->credit, d->masterId, d->department, log_student, d->name);
                        printf("You're added to course successfully!\n");
                        break;
                    }
                    d = d->next;
                }
                if(flag){
                    printf("No course exists with given name and master!\n");
                    continue;
                }
            }
            else{
                printf("You should login as a student to add course!\n");
            }
        }
        else if(check_input(command, "give_course")){
            if(log_student != -1){
                char pname[100];
                pname[0] = 0;
                char name[100];
                name[0] = 0;
                char f_first[100];
                f_first[0] = 0;
                char f_last[100];
                f_last[0] = 0;
                sscanf(command, "give_course %s %s %s", name, f_first, f_last);
                if(name[0] == 0 || f_first[0] == 0 || f_last[0] == 0){
                    printf("Invalid inputs!\n");
                    continue;
                }
                int uu = 1;
                struct new* a = newCourses;
                while(a->next != NULL){
                    if(!strcmp(a->name, name)){
                        uu = 0;
                        break;
                    }
                    a = a->next;
                }
                struct dars* b = darsHa;
                while(b->next != NULL){
                    if(!strcmp(b->name, name)){
                        uu = 0;
                        break;
                    }
                    b = b->next;
                }
                if(uu){
                    printf("This course doesn't exist!\n");
                    continue;
                }
                uu = 1;
                int person = 0;
                struct daneshJo* y = daneshJoHa;
                while(y->next != NULL){
                    if(!strcmp(y->firstname, f_first) && !strcmp(y->lastname, f_last)){
                        person = y->id;
                        uu = 0;
                        break;
                    }
                    y = y->next;
                }
                if(uu){
                    printf("This person doesn't exist!\n");
                    continue;
                }
                uu = 1;
                b = darsHa;
                while(b->next != NULL){
                    if(!strcmp(b->name, name) && b->student_id== log_student){
                        uu = 0;
                        break;
                    }
                    b = b->next;
                }
                struct new* ans;
                struct BARDASHTEH* o = bardashteHa;
                while(o->next != NULL){
                    if(!strcmp(o->name, name) && o->stdid== log_student && o->status){
                        a = newCourses;
                        while(a->next != NULL){
                            if(!strcmp(a->name, o->name) && a->masterId == o->masterId && a->status){
                                strcpy(pname, a->pre);
                                ans = a;
                                break;
                            }
                            a = a->next;
                        }
                        uu = 0;
                        break;
                    }
                    o = o->next;
                }
                if(uu){
                    printf("You don't belong to the student list of given course!\n");
                    continue;
                }
                uu = 0;
                o = bardashteHa;
                while(o->next != NULL){
                    if(!strcmp(o->name, name) && o->stdid== person && o->status){
                        uu = 1;
                        break;
                    }
                    o = o->next;
                }
                b = darsHa;
                while(b->next != NULL){
                    if(!strcmp(b->name, name) && b->student_id== person){
                        uu = 1;
                        break;
                    }
                    b = b->next;
                }
                if(uu){
                    printf("This person has already have this course!\n");
                    continue;;
                }
                uu = 1;
                b = darsHa;
                while(b->next != NULL){
                    if(!strcmp(b->name, pname) && b->student_id== person){
                        uu = 0;
                        break;
                    }
                    b = b->next;
                }
                if(uu){
                    printf("Your friend hasn't pass preneeded courses yet!\n");
                    continue;
                }
                addToEnd_BardashteHa(ans->credit, ans->masterId, ans->department, person, name);
                o = bardashteHa;
                while(o->next != NULL){
                    if(!strcmp(o->name, name) && o->stdid== log_student && o->status){
                        o->status = 0;
                        break;
                    }
                    o = o->next;
                }
                printf("Course transferd to %s %s successfully!\n", f_first, f_last);
            }
            else{
                printf("You should login as a student to give course to your friend!\n");
            }
        }
        else if(check_input(command, "remove-s")){
            if(log_student != -1){
                char name[100];
                name[0] = 0;
                sscanf(command, "remove-s %s", name);
                if(name[0] == 0){printf("Invalid inputs!\n"); continue;}
                int have = 0;
                struct BARDASHTEH* a = bardashteHa;
                while(a->next != NULL){
                    if(!strcmp(a->name, name) && a->stdid == log_student && a->status)
                        have = 1;
                    a = a->next;
                }
                struct dars* b = darsHa;
                while(b->next != NULL){
                    if(!strcmp(b->name, name) && b->student_id == log_student)
                        have = 1;
                    b = b->next;
                }
                if(!have){
                    printf("You don't belong to the student list of given course!\n");
                    continue;
                }
                int havePast = 0;
                b = darsHa;
                while(b->next != NULL){
                    if(!strcmp(b->name, name) && b->student_id == log_student)
                        havePast = 1;
                    b = b->next;
                }
                if(havePast){
                    printf("You have already had this course!\n");
                    continue;
                }
                a = bardashteHa;
                while(a->next != NULL){
                    if(!strcmp(a->name, name) && a->stdid == log_student){
                        a->status = 0;
                    }
                    a = a->next;
                }
                printf("The course is removed from your chart successfully!\n");
            }
            else{
                printf("You should login as a student to remove course!\n");
            }
        }
        else if(check_input(command, "change-group")){
            if(log_student != -1){
                char name[100];
                name[0] = 0;
                char masterFname[100];
                masterFname[0] = 0;
                char masterLname[100];
                masterLname[0] = 0;
                sscanf(command, "change-group %s %s %s", name, masterFname, masterLname);
                if(name[0] == 0 || masterFname[0] == 0 || masterLname[0] == 0){printf("Invalid inputs!\n"); continue;}
                int have = 0;
                struct new* a = newCourses;
                while(a->next != NULL){
                    if(!strcmp(a->name, name) && a->status)
                        have = 1;
                    a = a->next;
                }
                if(!have){
                    printf("This course doesn't exists!\n");
                    continue;
                }
                have = 0;
                a = newCourses;
                while(a->next != NULL){
                    if(findName_ostad(masterFname, masterLname) == NULL){
                        break;
                    }
                    if(a->masterId == findName_ostad(masterFname, masterLname)->id && a->status)
                        have = 1;
                    a = a->next;
                }
                if(!have){
                    printf("This master doesn't exists!\n");
                    continue;
                }
                have = 0;
                a = newCourses;
                while(a->next != NULL){
                    if(a->masterId == findName_ostad(masterFname, masterLname)->id && a->status && !strcmp(a->name, name))
                        have = 1;
                    a = a->next;
                }
                if(!have){
                    printf("This master doesn't present this course!\n");
                    continue;
                }
                struct BARDASHTEH* b = bardashteHa;
                int yy = 0;
                while(b->next != NULL){
                    int flag = 0;
                    if(b->stdid == log_student && !strcmp(b->name, name) && b->status){
                        a = newCourses;
                        while(a->next != NULL){
                            if(a->masterId == findName_ostad(masterFname, masterLname)->id && a->status && !strcmp(a->name, name)){
                                b->masterId = a->masterId;
                                printf("Course group changed to %s group successfully!\n", masterLname);
                                flag = 1;
                                break;
                            }
                            a = a->next;
                        }
                    }
                    if(flag){
                        yy = 1;
                        break;
                    }
                    b = b->next;
                }
                if(yy){
                    continue;
                }
                printf("You don't belong to the student list of given course!\n");
            }
            else{
                printf("You should login as a student to change group!\n");
            }
        }
        else{
            printf("Invalid command!\n");
        }
    }
    return 0;
}