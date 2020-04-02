#include "mlx.h"

int main(void)
{
  void *mlx;
  void *window;
  
  mlx = mlx_init();
  window = mlx_new_window(mlx, 1000, 800, "Leo");
  
  mlx_loop(mlx);
  return (0);
}