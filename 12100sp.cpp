#include <cstdio>
#include <queue>
#include <vector>
using namespace  std;
int  main () {
    int  t;
    scanf ( "% d" , & t);
    while (t --) {
        priority_queue < int , vector < int >> pq;
        queue < int > q;
        int  n, m, x, sum = 0;
        scanf ( "%d %d" , &n, &m);
        for  ( int  i = 0; i <n; ++ i) {
            scanf ( "%d" , &x);
            pq.push (x);
            q.push (x);
        }
        for  (;;) {
            if  (pq.top()==q.front())
            {
                sum ++;
                if  (! (m--)) break ;
                pq.pop (); q.pop ();
            }
            else  {
                if  (! (m --)) m = q.size () - 1;
                q.push (q.front ());
                q.pop ();
            }
        }
        printf ( "%d\n" , sum);
    }
    return  0;
}
