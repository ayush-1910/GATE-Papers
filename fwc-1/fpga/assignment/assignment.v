
module helloworldfpga (    
             
                input X,
                input Y,
                input C,
                output out
                );


wire t1,t2;
and(t1,X,~C);
and(t2,Y,C);
or(out,t1,t2);
endmodule  
