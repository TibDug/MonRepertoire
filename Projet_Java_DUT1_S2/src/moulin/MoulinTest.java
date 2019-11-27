package moulin;
import static org.junit.Assert.*;

import org.junit.Test;

public class MoulinTest {
	private final int MAXCOUPS = 20;
	private final int N = Moulin.getTaille();


	@Test
	public void test() {
		Moulin m = new Moulin(MAXCOUPS);
		
		assertEquals(m.getMaxCoups(), MAXCOUPS);
		assertEquals("...\n...\n...\n0", m.toString());
		
		assertTrue(Moulin.xyEstValide(1, 1));
		assertTrue(Moulin.xyEstValide(1, N));
		assertTrue(Moulin.xyEstValide(N, 1));
		assertTrue(Moulin.xyEstValide(N, N));
		assertFalse(Moulin.xyEstValide(0, 0));
		assertFalse(Moulin.xyEstValide(1, 0));
		assertFalse(Moulin.xyEstValide(0, N));
		assertFalse(Moulin.xyEstValide(1, N+1));
		assertFalse(Moulin.xyEstValide(N+1, 1));
		
		assertEquals(m.getNBCoups(), 0);
		assertEquals(m.getPion(2, 2), '.');
		assertEquals('O',m.aQui());
		m.placer(2, 2);
		
		assertEquals("...\n.O.\n...\n1", m.toString());
		assertEquals(m.getNBCoups(), 1);
		assertEquals(m.getPion(2,2), 'O');
		assertEquals('X',m.aQui());
		
		m.placer(1, 1);
		assertEquals("...\n.O.\nX..\n2", m.toString());
		assertEquals(m.getNBCoups(), 2);
		assertEquals(m.getPion(1, 1), 'X');
		
		
		m.placer(1,3);
		assertEquals("O..\n.O.\nX..\n3", m.toString());
		assertEquals(m.getNBCoups(), 3);
		assertEquals(m.getPion(1, 3), 'O');

		String position = ".XO\n.OX\nOX.\n10";
		System.out.println(position);

		m = new Moulin(position);

		assertEquals(position, m.toString());
		assertTrue(m.alignement(3, 3));
		assertTrue(m.alignement(1, 1));
		assertTrue(m.alignement(2, 2));
		assertFalse(m.alignement(2, 3));
		assertFalse(m.alignement(3, 2));
		assertFalse(m.alignement(2, 1));
		assertFalse(m.alignement(1, 2));
		assertFalse(m.alignement(1, 3));
		assertFalse(m.alignement(3, 1));
		assertTrue(m.alignement());

		position = "..O\n.XX\nOXO\n11";
		System.out.println(position);
		m = new Moulin(position);

		assertEquals(position, m.toString());
		assertFalse(m.alignement(3, 3));
		assertFalse(m.alignement(1, 1));
		assertFalse(m.alignement(2, 2));
		assertFalse(m.alignement(2, 3));
		assertFalse(m.alignement(3, 2));
		assertFalse(m.alignement(2, 1));
		assertFalse(m.alignement(1, 2));
		assertFalse(m.alignement(1, 3));
		assertFalse(m.alignement(3, 1));
		assertFalse(m.alignement());		
		
		assertTrue(m.peutDéplacerEn(2, 2, 1, 3));
		assertTrue(m.peutDéplacerEn(2, 2, 1, 2));
		assertTrue(m.peutDéplacerEn(2, 2, 2, 3));
		assertFalse(m.peutDéplacerEn(3, 3, 2, 3));
		assertFalse(m.peutDéplacerEn(1, 1, 1, 2));
		assertFalse(m.peutDéplacerEn(2, 1, 1, 2));
		assertFalse(m.peutDéplacerEn(3, 2, 2, 3));
		assertFalse(m.peutDéplacerEn(1, 3, 2, 3));
		assertFalse(m.peutDéplacerEn(3, 3, 1, 3));
		
		m.déplacerEn(2,2,1,3);
		position = "X.O\n..X\nOXO\n12";
		System.out.println(position);
		assertEquals(position, m.toString());
		assertEquals('O',m.aQui());  
		
		position = "..O\nX.O\nXXO\n7";
		System.out.println(position);
		m = new Moulin(position);
		assertEquals(position, m.toString());
		assertTrue(m.alignement(3,2));
		
		position = "O..\nXOX\n.XO\n9";
		System.out.println(position);
		m = new Moulin(position);
		assertEquals(position, m.toString());
		assertTrue(m.alignement(1,3));
	}
}
