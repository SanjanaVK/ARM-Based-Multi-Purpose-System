int main(void)
{
	  spi_init();   //Init SPI0
	  while(1)
	 {
		  nrf_config_write();

		  nrf_config_read();

	  }
}
