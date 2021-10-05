int main()
{
int pid, pipeDesc[2];
if ( pipe(pipeDesc) < 0) {
perror("pipe");
return 0;
}
pid = fork();
if ( pid == 0 ) {
close( 1 );
dup ( pipeDesc[ 1 ] );
close ( pipeDesc[ 0 ]);
close ( pipeDesc[ 1 ]);
execl("/usr/bin/who", "who", NULL);
}
else {
close( 0 ) ;
dup ( pipeDesc[0] );
close ( pipeDesc[1] );
close( pipeDesc[0]);
execl("/bin/sort", "sort", NULL);
}
return 0;

}
