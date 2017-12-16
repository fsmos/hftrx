%                                                                                                                                       
%THIS IS A WIZARD GENERATED FILE. DO NOT EDIT THIS FILE!                                                                                
%                                                                                                                                       
%---------------------------------------------------------------------------------------------------------                              
%This is a filter withfixed coefficients 
%This Model Only Support Single Channel Input Data. 
%Please input:                                                                                                                          
%data vector: 		stimulation(1:n)                                                                                                 
%                                                                                                                                       
%    This Model Only Support FIR_WIDTH to 51 Bits
%                                                                                                                                       
%FILTER PARAMETER                                                                                                                       
%Input Data Type:	Signed
%Input Data Width:	32
%Decimation Factor:   10
%MSB Truncated Bits: 1
%LSB Truncated bits:22
%FIR Width (Full Calculation Width Before Output Width Adjust) :   55
%-----------------------------------------------------------------------------------------------------------

	%MegaWizard Scaled Coefficient Values
	function  output = fir_10_2ch_mlab_mat (stimulation, output)
	coef_matrix=[0 0 0 0 0 0 0 0 0 -5 -11 -19 -27 -35 -41 -43 -42 -34 -20 0 25 53 83 110 132 145 146 132 103 59 0 -67 -139 -210 -273 -319 -342 -337 -299 -229 -128 0 141 290 431 551 635 673 655 576 436 241 0 -261 -531 -783 -992 -1136 -1194 -1153 -1006 -756 -416 -5 445 900 1318 1661 1891 1977 1898 1648 1233 674 8 -717 -1441 -2101 -2636 -2987 -3110 -2975 -2573 -1916 -1043 -10 1104 2210 3213 4016 4537 4708 4490 3870 2874 1559 14 -1644 -3282 -4757 -5931 -6684 -6919 -6582 -5661 -4194 -2268 -18 2389 4756 6880 8563 9632 9955 9455 8119 6006 3243 22 -3414 -6786 -9806 -12193 -13704 -14153 -13434 -11529 -8523 -4598 -25 4851 9639 13928 17323 19478 20129 19119 16423 12152 6561 29 -6958 -13845 -20045 -24988 -28169 -29192 -27814 -23973 -17804 -9647 -32 10351 20697 30136 37806 42913 44809 43047 37435 28073 15369 35 -16941 -34343 -50793 -64833 -75026 -80041 -78763 -70367 -54399 -30820 -36 37102 79333 125039 172326 219124 263307 302804 335726 360473 375829 381034 375829 360473 335726 302804 263307 219124 172326 125039 79333 37102 -36 -30820 -54399 -70367 -78763 -80041 -75026 -64833 -50793 -34343 -16941 35 15369 28073 37435 43047 44809 42913 37806 30136 20697 10351 -32 -9647 -17804 -23973 -27814 -29192 -28169 -24988 -20045 -13845 -6958 29 6561 12152 16423 19119 20129 19478 17323 13928 9639 4851 -25 -4598 -8523 -11529 -13434 -14153 -13704 -12193 -9806 -6786 -3414 22 3243 6006 8119 9455 9955 9632 8563 6880 4756 2389 -18 -2268 -4194 -5661 -6582 -6919 -6684 -5931 -4757 -3282 -1644 14 1559 2874 3870 4490 4708 4537 4016 3213 2210 1104 -10 -1043 -1916 -2573 -2975 -3110 -2987 -2636 -2101 -1441 -717 8 674 1233 1648 1898 1977 1891 1661 1318 900 445 -5 -416 -756 -1006 -1153 -1194 -1136 -992 -783 -531 -261 0 241 436 576 655 673 635 551 431 290 141 0 -128 -229 -299 -337 -342 -319 -273 -210 -139 -67 0 59 103 132 146 145 132 110 83 53 25 0 -20 -34 -42 -43 -41 -35 -27 -19 -11 -5 0 0 0 0 0 0 0 0 0 0 ];
	INTER_FACTOR  = 1;
	DECI_FACTOR  = 10;
	MSB_RM  = 1;
	MSB_TYPE  = 0;
	LSB_RM  = 22;
	LSB_TYPE  = 0;
	FIR_WIDTH  = 55;
	OUT_WIDTH  = FIR_WIDTH - MSB_RM - LSB_RM ;
	DATA_WIDTH = 32;
            
	data_type= 1;

        % check size of inputs.
        [DX,DY] = size(stimulation);
        [CX,CY] = size(coef_matrix);
        if (CX ~= DY * INTER_FACTOR)
	        fprintf('WARNING : coef_matrix size and input data size is not match\n');
        end
        
        %fill coef_matrix to length of data with the latest coef set
        if (CX < DY * INTER_FACTOR)
            for i= CX +1:DY * INTER_FACTOR
                coef_matrix(i,:) = coef_matrix(CX,:);
            end
        end

        %check if input is integer
       	int_sti=round(stimulation);
	    T = (int_sti ~= stimulation);
	    if (max(T)~=0)
	        fprintf('WARNING : Integer Input Expected: Rounding Fractional Input to Nearest Integer...\n');
	    end
	    
	    %Input overflow check
	    switch  data_type
	    case 1
	        %set max/min for signed
	        maxdat = 2^(DATA_WIDTH-1)-1;
	        mindat = -maxdat-1;
	    case 2
	        %set max/min for unsigned
	        maxdat = 2^DATA_WIDTH-1;
	        mindat = 0;
	    end

	    if(data_type == 2)
	    	if(abs(coef_matrix) == coef_matrix)
	    		FIR_WIDTH = FIR_WIDTH +1;
	    	end
	    end

	    %Saturating Input Value
	    a=find(int_sti>maxdat);
	    b=find(int_sti<mindat);
	    if (~isempty(a)|~isempty(b))
	 	    fprintf('WARNING : Input Amplitude Exceeds MAXIMUM/MINIMUM allowable values - saturating input values...\n');
	            lena = length (a);
	            lenb = length (b);
	            for i =1:lena
	        	    fprintf('%d > %d \n', int_sti(a(i)), maxdat);
			        int_sti(a(i)) = maxdat;
		        end
		    for i =1:lenb
			    fprintf('%d < %d \n', int_sti(b(i)), mindat);
			    int_sti(b(i)) = mindat;
		    end
	    end
        
	    % Add interpolation
   	    inter_sti = zeros(1, INTER_FACTOR * length(int_sti));
	    inter_sti(1:INTER_FACTOR:INTER_FACTOR * length(int_sti)) = int_sti;

        
        for i = 1 : DY *INTER_FACTOR
    	    coef_current = coef_matrix(i,:);
            output_temp(i) = simp_adaptive (inter_sti, coef_current, i);
        end
	% Truncate output
	len1 = length(output_temp);
	
	    switch  LSB_TYPE
	    case 0
	        %truncate
            out_dec = bi_trunc_lsb(output_temp,LSB_RM,FIR_WIDTH);
	    case 1
	        %round
            out_dec = bi_round(output_temp,LSB_RM, FIR_WIDTH);
	    end
        
 	    switch  MSB_TYPE
	    case 0
	        %truncate
            out_dec = bi_trunc_msb(out_dec,MSB_RM,FIR_WIDTH-LSB_RM);
	    case 1
	        %round
            out_dec = bi_satu(out_dec,MSB_RM, FIR_WIDTH-LSB_RM);
	    end
 	   
    	% choose decimation output in phase=DECI_FACTOR-1  
     	if(DECI_FACTOR == 1)
     		output = out_dec;
     	else
     		output = out_dec(DECI_FACTOR:DECI_FACTOR:len1);
 	    end 
 	      
  	function[output, outindex] = simp_adaptive (int_sti, coef_current, data_index, output)
	%Simulation is the whole input sequence
	%coef_current is the current coefficient set
	%data_index gives the last data to use
	%outputs are the sum of input and coef multiplication
	%outindex is the next data_index
   
	sti_current = zeros(length(coef_current),1);
	
	data_length = length(int_sti);
	
	%Check data index
	if (data_index > data_length)
		fprintf('ERROR: DATA INDEX IS LARGER THAN DATA LENGTH!!!\n');
		return;
	end
	for i = 1: length(coef_current)
	   if ((data_index -i+1)>0 & (data_index - i+1)<=data_length)
	      sti_current(i,1) = int_sti(data_index - i+1);
	   end
	end
	
	outindex= data_index+1;
	output = coef_current * sti_current;
	% end of function simp_adaptive

	function output = bi_round(data_in,LSB_RM,ORI_WIDTH, output)
	% LSB_RM is the bit to lose in LSB
	% ORI_WIDTH is the original data width
	data = round (data_in / 2^LSB_RM);
	output = bi_satu(data,0,ORI_WIDTH - LSB_RM);
	%end of function bi_trunc_lsb
	
	function output = bi_trunc_lsb(data_in,LSB_RM,ORI_WIDTH, output)
	% LSB_RM is the bit to lose in LSB
	% ORI_WIDTH is the original data width
	%2's complement system
	output = bitshift(2^ORI_WIDTH*(data_in<0) + data_in, -LSB_RM) - 2^(ORI_WIDTH-LSB_RM) *(data_in<0);
	% end of function bi_round
	
	function output = bi_trunc_msb(data_in,MSB_RM,ORI_WIDTH, output)
	% MSB_RM is the bit to lose in LSB
	% ORI_WIDTH is the original data width
	%2's complement system
	data = 2^ORI_WIDTH * (data_in < 0)+ data_in;
	erase_num = 2^(ORI_WIDTH - MSB_RM) - 1;
	data = bitand(data, erase_num);
	output = data - 2^(ORI_WIDTH - MSB_RM)*(bitget(data,ORI_WIDTH - MSB_RM));
	%end of bi_trunc_msb
	
	function output = bi_satu(data_in,MSB_RM,ORI_WIDTH, output)
	% MSB_RM is the bit to lose in LSB
	% ORI_WIDTH is the original data width
	%2's complement system
	maxdat = 2^(ORI_WIDTH - MSB_RM -1)-1;
	mindat = 2^(ORI_WIDTH - MSB_RM -1)*(-1);
	data_in(find(data_in > maxdat)) = maxdat;
	data_in(find(data_in < mindat)) = mindat;
	output = data_in;
	%end of bi_satu 
