package sound;

import javax.sound.sampled.*;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.IOException;
import java.lang.Math;
import java.util.ArrayList;
import java.util.Scanner;

public class syn {
    static  final   int freq=44100;
    String str;
    Scanner scanner = new Scanner(System.in);
    public  syn() throws IOException{
    	
    	str = scanner.nextLine();
    	int n = str.length();
    	ArrayList <Integer> fre = new ArrayList();
    	int l = 0;
     	for(l = 0;l < n;l++)fre.add(str.codePointAt(l)) ;
     	for(l = 0;l < n-1;l++){
     		if(fre.get(l+1)==45){
     			if(fre.get(l)==49)fre.set(l,278);
     			if(fre.get(l)==50)fre.set(l,311);
     			if(fre.get(l)==52)fre.set(l,370);
     			if(fre.get(l)==53)fre.set(l,415);
     			if(fre.get(l)==54)fre.set(l,460);
     		}
     		else{
     			if(fre.get(l)==45)fre.set(l, 0);
     			if(fre.get(l)==49)fre.set(l,262);
     			if(fre.get(l)==50)fre.set(l,294);
     			if(fre.get(l)==51)fre.set(l,330);
     			if(fre.get(l)==52)fre.set(l,349);
     			if(fre.get(l)==53)fre.set(l,392);
     			if(fre.get(l)==54)fre.set(l,440);
     			if(fre.get(l)==55)fre.set(l,494);
     		}
     	}
     	if(fre.get(n-1)==45)fre.set(l, 0);
     	else{
     		if(fre.get(l)==49)fre.set(l,65);
 			if(fre.get(l)==50)fre.set(l,73);
 			if(fre.get(l)==51)fre.set(l,82);
 			if(fre.get(l)==52)fre.set(l,87);
 			if(fre.get(l)==53)fre.set(l,98);
 			if(fre.get(l)==54)fre.set(l,110);
 			if(fre.get(l)==55)fre.set(l,124);
     	}
     	for(int i=0;i<fre.size();i++){
     		if(fre.get(i)==0)fre.remove(i);
     	}
     	
     	AudioFormat fmt=new AudioFormat(freq, 8, 1, true, false);
     	byte[] data=new byte[(freq+20)*fre.size()];
     	int k=0;
     	
     	for(int i=0;i<fre.size();i++){
     		try{

                for(int j=0;j<freq;j++){
                    data[k]=(byte)(127*Math.sin(2*Math.PI*fre.get(i)*j/freq));
                    k++;
                }
                for(int j=freq;j<freq+20;j++){
                    data[k]=(byte)(0);
                    k++;
                }
                
            }catch(Exception e){
                e.printStackTrace();
                System.exit(1);
            }
     	}

     	File out = new File("out.wav");
     	ByteArrayInputStream bais = new ByteArrayInputStream(data);
        AudioInputStream audioInputStream;
        audioInputStream = new AudioInputStream(bais, fmt,(freq+20)*fre.size());
        AudioSystem.write(audioInputStream, AudioFileFormat.Type.WAVE, out);
        audioInputStream.close();

    }
    public static void main(String[] args) throws IOException{
        new syn();
    }
}