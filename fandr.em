
macro atest ()
{
	table = GetCurrentBuf ()
	tl = GetBufLnCur (table)
	lb = GetBufLine(table,tl)

	i=0
	j=strlen(lb)
	k=0
	while(k!=6)
	{
		tmp = AsciiFromChar(lb[i])
		i++
		if (tmp != 34)
			continue
		k++
		if(k ==3)
			k3 = i
		if(k ==4)
			k4 = i-1
		if(k ==5)
			k5 = i
		if(k ==6)
			k6 = i-1
	}
	
	
	scn = strmid(lb,k3,k4)
	sen = strmid(lb,k5,k6)

    hbuf = NewBuf("Results") // create output buffer
    if (hbuf == 0)
        stop
    SearchForRefs(hbuf, sen, 0)
    SetCurrentBuf(hbuf) // put buffer in a window
    totalLine = GetBufLineCount(hbuf)

    i = 0
    preF = ""
    while (i<totalLine)
    {
		lr=GetSourceLink(hbuf,i)
		hwbuf=OpenBuf(lr.File)
		if (preF == lr.File)
		{
			i++
			continue
		}
		
    	SetCurrentBuf(hwbuf) // put buffer in a window
    	if (i==0)
    	{
			if(lr.ln>=20)
				gline = lr.ln - 19
			else
				gline = 0
			hwnd = GetWndHandle(hwbuf)
	    	ScrollWndToLine(hwnd,gline ) 
			sz = Ask("test")

			ii=0
			j=strlen(sz)
			k = 0
			rcn =""
			ren =""
			while(ii<j)
			{
				tmp = AsciiFromChar(sz[ii])
				ii++
				if (tmp != 32)
					continue

				k = ii-1
				break
			}
			rcn = strmid(sz,0,k)
			ren = strmid(sz,k+1,j)
		}
		lnlim = GetBufLineCount(hwbuf)
		ReplaceInBuf(hwbuf, sen, ren, 0, lnLim, True, False, True, True)

		if(rcn!="")
			ReplaceInBuf(hwbuf, scn, rcn, 0, lnLim, True, False, True, True)
		
		SaveBuf(hwbuf)
		preF = lr.File
		i++
    }


}

