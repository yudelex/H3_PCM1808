/*
 * ALSA SoC PCM1808 support
 *
 * Author: yudelex
 *
 *
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>

#include <sound/soc.h>

static struct snd_soc_dai_driver pcm1808_dai = {
	.name		= "pcm1808",
	.capture        = {
		.stream_name	= "Capture",
		.channels_min	= 2,
		.channels_max	= 2,
		.rates		= SNDRV_PCM_RATE_48000 | SNDRV_PCM_RATE_64000 | SNDRV_PCM_RATE_96000,
		.formats	= SNDRV_PCM_FMTBIT_S24_LE,
	},
};

static const struct snd_soc_component_driver soc_component_dev_pcm1808 = {
	.idle_bias_on		= 1,
	.use_pmdown_time	= 1,
	.endianness		= 1,
};

static int pcm1808_codec_probe(struct platform_device *pdev)
{
	return devm_snd_soc_register_component(&pdev->dev, &soc_component_dev_pcm1808,
			&pcm1808_dai, 1);
}

static const struct of_device_id pcm1808_codec_dt_ids[] = {
	{ .compatible = "ti,pcm1808", },
	{ }
};
MODULE_DEVICE_TABLE(of, pcm1808_codec_dt_ids);

static struct platform_driver pcm1808_codec_driver = {
	.probe		= pcm1808_codec_probe,
	.driver		= {
		.name	= "pcm1808-codec",
		.of_match_table = of_match_ptr(pcm1808_codec_dt_ids),
	},
};

module_platform_driver(pcm1808_codec_driver);

MODULE_AUTHOR("yudelex");
MODULE_DESCRIPTION("PCM1808 driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:pcm1808-codec");